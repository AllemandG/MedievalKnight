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