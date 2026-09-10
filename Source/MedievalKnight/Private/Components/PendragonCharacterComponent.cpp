#include "MedievalKnight/Public/Components/PendragonCharacterComponent.h"

UPendragonCharacterComponent::UPendragonCharacterComponent()
{
    PrimaryComponentTick.bCanEverTick = false;

    // Initialize default trait values (10/10 balance by default)
    Traits.Add(EPendragonTrait::Chaste_Lustful, 10);
    Traits.Add(EPendragonTrait::Energetic_Lazy, 10);
    Traits.Add(EPendragonTrait::Forgiving_Vengeful, 10);
    Traits.Add(EPendragonTrait::Generous_Selfish, 10);
    Traits.Add(EPendragonTrait::Honest_Deceitful, 10);
    Traits.Add(EPendragonTrait::Just_Arbitrary, 10);
    Traits.Add(EPendragonTrait::Merciful_Cruel, 10);
    Traits.Add(EPendragonTrait::Modest_Proud, 10);
    Traits.Add(EPendragonTrait::Pious_Worldly, 10);
    Traits.Add(EPendragonTrait::Prudent_Reckless, 10);
    Traits.Add(EPendragonTrait::Temperate_Indulgent, 10);
    Traits.Add(EPendragonTrait::Trusting_Suspicious, 10);
    Traits.Add(EPendragonTrait::Valiant_Cowardly, 10);
}

void UPendragonCharacterComponent::BeginPlay()
{
    Super::BeginPlay();

    // Ensure health is initialized properly on startup
    Attributes.CurrentHealth = Attributes.GetMaxHealth();
}

int32 UPendragonCharacterComponent::GetTraitValue(EPendragonTrait TraitPair, bool bGetPrimary) const
{
    const int32* PrimaryValue = Traits.Find(TraitPair);
    int32 Val = PrimaryValue ? *PrimaryValue : 10;

    return bGetPrimary ? Val : (20 - Val);
}

void UPendragonCharacterComponent::SetTraitValue(EPendragonTrait TraitPair, int32 NewValue)
{
    int32 ClampedValue = FMath::Clamp(NewValue, 0, 20);
    Traits.Add(TraitPair, ClampedValue);
}

EPendragonCheckResult UPendragonCharacterComponent::PerformD20Check(int32 TargetValue, int32& OutRoll)
{
    OutRoll = FMath::RandRange(1, 20);

    // Critical Success: Exact match to TargetValue, or 20 if TargetValue >= 20
    if ((OutRoll == TargetValue) || (TargetValue >= 20 && OutRoll == 20))
    {
        return EPendragonCheckResult::CriticalSuccess;
    }

    // Fumble: Rolling 20 when TargetValue < 20
    if (OutRoll == 20 && TargetValue < 20)
    {
        return EPendragonCheckResult::Fumble;
    }

    // Standard Success / Failure
    if (OutRoll <= TargetValue)
    {
        return EPendragonCheckResult::Success;
    }

    return EPendragonCheckResult::Failure;
}

EPendragonCheckResult UPendragonCharacterComponent::CheckTrait(EPendragonTrait TraitPair, bool bCheckPrimary, int32& OutRoll) const
{
    int32 TargetVal = GetTraitValue(TraitPair, bCheckPrimary);
    return PerformD20Check(TargetVal, OutRoll);
}

void UPendragonCharacterComponent::AddOrUpdatePassion(EPendragonPassionType Type, const FString& Target, int32 Value)
{
    for (FPendragonPassion& Passion : Passions)
    {
        if (Passion.PassionType == Type && Passion.Target.Equals(Target, ESearchCase::IgnoreCase))
        {
            Passion.Value = FMath::Clamp(Value, 0, 20);
            return;
        }
    }

    FPendragonPassion NewPassion;
    NewPassion.PassionType = Type;
    NewPassion.Target = Target;
    NewPassion.Value = FMath::Clamp(Value, 0, 20);
    Passions.Add(NewPassion);
}

int32 UPendragonCharacterComponent::GetPassionValue(EPendragonPassionType Type, const FString& Target) const
{
    for (const FPendragonPassion& Passion : Passions)
    {
        if (Passion.PassionType == Type && Passion.Target.Equals(Target, ESearchCase::IgnoreCase))
        {
            return Passion.Value;
        }
    }
    return 0;
}

void UPendragonCharacterComponent::SetSkillValue(FName SkillID, int32 Value)
{
    if (FPendragonSkillData* Skill = CharacterSkills.Find(SkillID))
    {
        Skill->Value = FMath::Max(0, Value);
    }
    else
    {
        FPendragonSkillData NewSkill;
        NewSkill.SkillID = SkillID;
        NewSkill.DisplayName = FText::FromName(SkillID);
        NewSkill.Value = FMath::Max(0, Value);
        CharacterSkills.Add(SkillID, NewSkill);
    }
}

int32 UPendragonCharacterComponent::GetSkillValue(FName SkillID) const
{
    if (const FPendragonSkillData* Skill = CharacterSkills.Find(SkillID))
    {
        return Skill->Value;
    }
    return 0;
}

void UPendragonCharacterComponent::CheckSkillForImprovement(FName SkillID)
{
    if (FPendragonSkillData* Skill = CharacterSkills.Find(SkillID))
    {
        Skill->bCheckedForImprovement = true;
    }
}

void UPendragonCharacterComponent::CheckPassionForImprovement(EPendragonPassionType Type, const FString& Target)
{
    for (FPendragonPassion& Passion : Passions)
    {
        if (Passion.PassionType == Type && Passion.Target.Equals(Target, ESearchCase::IgnoreCase))
        {
            Passion.bCheckedForImprovement = true;
        }
    }
}
