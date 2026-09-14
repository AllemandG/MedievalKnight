#include "MedievalKnight/Public/Story/StorySubsystem.h"
#include "MedievalKnight/Public/Components/PendragonCharacterComponent.h"
#include "Engine/AssetManager.h"

void UStorySubsystem::StartStory(UStoryNodeDataAsset* StartingNode, UPendragonCharacterComponent* PlayerCharacter)
{
    CharacterComponent = PlayerCharacter;
    CurrentNode = StartingNode;

    if (CurrentNode)
    {
        OnStoryNodeChanged.Broadcast(CurrentNode);
    }
}

bool UStorySubsystem::EvaluateRequirement(const FPendragonRequirement& Req) const
{
    if (!CharacterComponent) return false;

    switch (Req.RequirementType)
    {
    case ERequirementType::Trait:
        return CharacterComponent->GetTraitValue(Req.Trait, Req.bCheckPrimaryTrait) >= Req.MinimumValue;

    case ERequirementType::Attribute:
        if (Req.Name == "Size") return CharacterComponent->Attributes.Size >= Req.MinimumValue;
        if (Req.Name == "Strength") return CharacterComponent->Attributes.Strength >= Req.MinimumValue;
        if (Req.Name == "Dexterity") return CharacterComponent->Attributes.Dexterity >= Req.MinimumValue;
        if (Req.Name == "Constitution") return CharacterComponent->Attributes.Constitution >= Req.MinimumValue;
        if (Req.Name == "Appeal") return CharacterComponent->Attributes.Appeal >= Req.MinimumValue;
        break;

    case ERequirementType::Skill:
        return CharacterComponent->GetSkillValue(Req.Name) >= Req.MinimumValue;

    case ERequirementType::Passion:
        for (const FPendragonPassion& Passion : CharacterComponent->Passions)
        {
            if (Passion.Target.Equals(Req.Name.ToString(), ESearchCase::IgnoreCase) ||
                Passion.GetDisplayName().ToString().Equals(Req.Name.ToString(), ESearchCase::IgnoreCase))
            {
                return Passion.Value >= Req.MinimumValue;
            }
        }
        return false;
    }

    return false;
}

bool UStorySubsystem::CanSelectChoice(const FStoryChoice& Choice) const
{
    for (const FPendragonRequirement& Req : Choice.Requirements)
    {
        if (!EvaluateRequirement(Req))
        {
            return false;
        }
    }
    return true;
}

void UStorySubsystem::ApplyEffect(const FPendragonEffect& Effect)
{
    if (!CharacterComponent) return;

    switch (Effect.EffectType)
    {
    case EEffectType::ModifyTrait:
    {
        int32 CurrentVal = CharacterComponent->GetTraitValue(Effect.Trait, true);
        CharacterComponent->SetTraitValue(Effect.Trait, CurrentVal + Effect.ModifierValue);
        break;
    }
    case EEffectType::ModifyHealth:
    {
        CharacterComponent->Attributes.CurrentHealth = FMath::Clamp(
            CharacterComponent->Attributes.CurrentHealth + Effect.ModifierValue,
            0,
            CharacterComponent->Attributes.GetMaxHealth()
        );
        break;
    }
    case EEffectType::ModifySkill:
    {
        int32 CurrentSkillVal = CharacterComponent->GetSkillValue(Effect.Name);
        CharacterComponent->SetSkillValue(Effect.Name, CurrentSkillVal + Effect.ModifierValue);
        break;
    }
    case EEffectType::ModifyPassion:
    {
        for (FPendragonPassion& Passion : CharacterComponent->Passions)
        {
            if (Passion.Target.Equals(Effect.Name.ToString(), ESearchCase::IgnoreCase) ||
                Passion.GetDisplayName().ToString().Equals(Effect.Name.ToString(), ESearchCase::IgnoreCase))
            {
                Passion.Value = FMath::Clamp(Passion.Value + Effect.ModifierValue, 0, 20);
                break;
            }
        }
        break;
    }
    }
}

void UStorySubsystem::SelectChoice(int32 ChoiceIndex)
{
    if (!CurrentNode || !CurrentNode->Choices.IsValidIndex(ChoiceIndex)) return;

    const FStoryChoice& Choice = CurrentNode->Choices[ChoiceIndex];

    if (!CanSelectChoice(Choice)) return;

    if (Choice.bRequiresCheck)
    {
        int32 TargetValue = 10;
        FName ResolvedCheckName = NAME_None;

        // 1. Résolution de la valeur cible selon le type de test
        switch (Choice.CheckType)
        {
        case ERequirementType::Trait:
        {
            TargetValue = CharacterComponent ? CharacterComponent->GetTraitValue(Choice.CheckTrait, Choice.bCheckPrimaryTrait) : 10;
            UEnum* TraitEnum = StaticEnum<EPendragonTrait>();
            ResolvedCheckName = TraitEnum ? FName(*TraitEnum->GetDisplayNameTextByValue(static_cast<int64>(Choice.CheckTrait)).ToString()) : FName(TEXT("Trait"));
            break;
        }
        case ERequirementType::Skill:
        {
            ResolvedCheckName = Choice.CheckName;
            TargetValue = CharacterComponent ? CharacterComponent->GetSkillValue(Choice.CheckName) : 10;
            break;
        }
        case ERequirementType::Passion:
        {
            ResolvedCheckName = Choice.CheckName;
            if (CharacterComponent)
            {
                for (const FPendragonPassion& Passion : CharacterComponent->Passions)
                {
                    if (Passion.Target.Equals(Choice.CheckName.ToString(), ESearchCase::IgnoreCase) ||
                        Passion.GetDisplayName().ToString().Equals(Choice.CheckName.ToString(), ESearchCase::IgnoreCase))
                    {
                        TargetValue = Passion.Value;
                        break;
                    }
                }
            }
            break;
        }
        case ERequirementType::Attribute:
        {
            ResolvedCheckName = Choice.CheckName;
            if (CharacterComponent)
            {
                if (Choice.CheckName == "Size") TargetValue = CharacterComponent->Attributes.Size;
                else if (Choice.CheckName == "Strength") TargetValue = CharacterComponent->Attributes.Strength;
                else if (Choice.CheckName == "Dexterity") TargetValue = CharacterComponent->Attributes.Dexterity;
                else if (Choice.CheckName == "Constitution") TargetValue = CharacterComponent->Attributes.Constitution;
                else if (Choice.CheckName == "Appeal") TargetValue = CharacterComponent->Attributes.Appeal;
            }
            break;
        }
        }

        // 2. Jet d20
        int32 Roll = 0;
        EPendragonCheckResult Result = UPendragonCharacterComponent::PerformD20Check(TargetValue, Roll);

        OnCheckResolved.Broadcast(Result, Roll, TargetValue, ResolvedCheckName);

        // 3. Application de la case de progression (Check for Improvement) en cas de succès
        if ((Result == EPendragonCheckResult::Success || Result == EPendragonCheckResult::CriticalSuccess) && CharacterComponent)
        {
            switch (Choice.CheckType)
            {
            case ERequirementType::Trait:
                CharacterComponent->CheckTraitForImprovement(Choice.CheckTrait, Choice.bCheckPrimaryTrait);
                break;
            case ERequirementType::Skill:
                CharacterComponent->CheckSkillForImprovement(Choice.CheckName);
                break;
            case ERequirementType::Passion:
                // Coche la passion correspondante
                for (FPendragonPassion& Passion : CharacterComponent->Passions)
                {
                    if (Passion.Target.Equals(Choice.CheckName.ToString(), ESearchCase::IgnoreCase) ||
                        Passion.GetDisplayName().ToString().Equals(Choice.CheckName.ToString(), ESearchCase::IgnoreCase))
                    {
                        Passion.bCheckedForImprovement = true;
                        break;
                    }
                }
                break;
            case ERequirementType::Attribute:
                if (Choice.CheckName == "Size") CharacterComponent->CheckAttributeForImprovement(EPendragonAttribute::Size);
                else if (Choice.CheckName == "Strength") CharacterComponent->CheckAttributeForImprovement(EPendragonAttribute::Strength);
                else if (Choice.CheckName == "Dexterity") CharacterComponent->CheckAttributeForImprovement(EPendragonAttribute::Dexterity);
                else if (Choice.CheckName == "Constitution") CharacterComponent->CheckAttributeForImprovement(EPendragonAttribute::Constitution);
                else if (Choice.CheckName == "Appeal") CharacterComponent->CheckAttributeForImprovement(EPendragonAttribute::Appeal);
                break;
            }
        }

        // 4. Transition vers le nœud de destination
        TSoftObjectPtr<UStoryNodeDataAsset> TargetNode = Choice.FailureNode;

        switch (Result)
        {
        case EPendragonCheckResult::CriticalSuccess:
            TargetNode = Choice.CriticalSuccessNode.IsNull() ? Choice.SuccessNode : Choice.CriticalSuccessNode;
            break;
        case EPendragonCheckResult::Success:
            TargetNode = Choice.SuccessNode;
            break;
        case EPendragonCheckResult::Failure:
            TargetNode = Choice.FailureNode;
            break;
        case EPendragonCheckResult::Fumble:
            TargetNode = Choice.FumbleNode.IsNull() ? Choice.FailureNode : Choice.FumbleNode;
            break;
        }

        TransitionToNode(TargetNode);
    }
    else
    {
        for (const FPendragonEffect& Effect : Choice.DirectEffects)
        {
            ApplyEffect(Effect);
        }

        TransitionToNode(Choice.NextNode);
    }
}

void UStorySubsystem::TransitionToNode(TSoftObjectPtr<UStoryNodeDataAsset> NextNodePtr)
{
    if (NextNodePtr.IsNull()) return;

    if (UStoryNodeDataAsset* LoadedNode = NextNodePtr.Get())
    {
        CurrentNode = LoadedNode;
        OnStoryNodeChanged.Broadcast(CurrentNode);
    }
    else
    {
        // Chargement asynchrone / synchrone si pas encore en mémoire
        CurrentNode = NextNodePtr.LoadSynchronous();
        if (CurrentNode)
        {
            OnStoryNodeChanged.Broadcast(CurrentNode);
        }
    }
}