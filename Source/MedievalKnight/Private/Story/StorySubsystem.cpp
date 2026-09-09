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
        if (Req.Name == "Appearance") return CharacterComponent->Attributes.Appearance >= Req.MinimumValue;
        break;

    case ERequirementType::Skill:
        if (const int32* Val = CharacterComponent->Skills.Find(Req.Name))
        {
            return *Val >= Req.MinimumValue;
        }
        return false;

    case ERequirementType::Passion:
        for (const FPendragonPassion& Passion : CharacterComponent->Passions)
        {
            if (Passion.PassionName == Req.Name)
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
        int32& Val = CharacterComponent->Skills.FindOrAdd(Effect.Name, 0);
        Val = FMath::Max(0, Val + Effect.ModifierValue);
        break;
    }
    case EEffectType::ModifyPassion:
    {
        for (FPendragonPassion& Passion : CharacterComponent->Passions)
        {
            if (Passion.PassionName == Effect.Name)
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

        if (Choice.CheckType == ERequirementType::Trait)
        {
            TargetValue = CharacterComponent ? CharacterComponent->GetTraitValue(Choice.CheckTrait, Choice.bCheckPrimaryTrait) : 10;
        
            UEnum* TraitEnum = StaticEnum<EPendragonTrait>();
            ResolvedCheckName = TraitEnum ? FName(*TraitEnum->GetDisplayNameTextByValue(static_cast<int64>(Choice.CheckTrait)).ToString()) : FName(TEXT("Trait"));
        }
        else if (Choice.CheckType == ERequirementType::Skill)
        {
            ResolvedCheckName = Choice.CheckName;
            if (const int32* Val = CharacterComponent->Skills.Find(Choice.CheckName))
            {
                TargetValue = *Val;
            }
        }

        int32 Roll = 0;
        EPendragonCheckResult Result = UPendragonCharacterComponent::PerformD20Check(TargetValue, Roll);

        OnCheckResolved.Broadcast(Result, Roll, TargetValue, ResolvedCheckName);

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