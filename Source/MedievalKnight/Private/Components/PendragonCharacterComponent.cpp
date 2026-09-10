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

    // ==========================================
    // 1. DONNÉES DE TEST : PASSIONS DE DÉPART
    // ==========================================
    AddOrUpdatePassion(EPendragonPassionType::Loyalty,      TEXT("Lord Roderick"),  15);
    AddOrUpdatePassion(EPendragonPassionType::Duty,         TEXT("Vassalage"),      12);
    AddOrUpdatePassion(EPendragonPassionType::Love,         TEXT("Family"),         13);
    AddOrUpdatePassion(EPendragonPassionType::Hate,         TEXT("English"),        14);
    AddOrUpdatePassion(EPendragonPassionType::Hospitality,  TEXT("Realm"),          10);
    AddOrUpdatePassion(EPendragonPassionType::Devotion,     TEXT("Deity"),          5);
    AddOrUpdatePassion(EPendragonPassionType::Station,      TEXT("Personal"),       5);
    AddOrUpdatePassion(EPendragonPassionType::Honor,        TEXT("Personal"),       15);

    // ==========================================
    // 2. DONNÉES DE TEST : COMPÉTENCES DE DÉPART
    // ==========================================
    auto RegisterSkill = [this](FName ID, const FString& Name, int32 Val, EPendragonSkillCategory Cat, bool bKnightly)
    {
        FPendragonSkillData Skill;
        Skill.SkillID = ID;
        Skill.DisplayName = FText::FromString(Name);
        Skill.Value = Val;
        Skill.Category = Cat;
        Skill.bIsKnightlySkill = bKnightly;
        Skill.bCheckedForImprovement = false;
        CharacterSkills.Add(ID, Skill);
    };

    // --- Compétences de Chevalier : Combat ---
    RegisterSkill(TEXT("Battle"),       TEXT("Battle"),       10, EPendragonSkillCategory::Combat,   true);
    RegisterSkill(TEXT("Horsemanship"), TEXT("Horsemanship"), 15, EPendragonSkillCategory::Combat,   true);
    RegisterSkill(TEXT("Brawling"),     TEXT("Brawling"),     10, EPendragonSkillCategory::Combat,   true);
    RegisterSkill(TEXT("Charge"),       TEXT("Charge"),       13, EPendragonSkillCategory::Combat,   true);
    RegisterSkill(TEXT("Sword"),        TEXT("Sword"),        15, EPendragonSkillCategory::Combat,   true);

    // --- Compétences de Chevalier : Civiles / Non-Combat ---
    RegisterSkill(TEXT("Awareness"),    TEXT("Awareness"),    10, EPendragonSkillCategory::Civilian, true);
    RegisterSkill(TEXT("Courtesy"),     TEXT("Courtesy"),     12, EPendragonSkillCategory::Civilian, true);
    RegisterSkill(TEXT("FirstAid"),     TEXT("First Aid"),    10, EPendragonSkillCategory::Civilian, true);
    RegisterSkill(TEXT("Hunting"),      TEXT("Hunting"),      10, EPendragonSkillCategory::Civilian, true);
    RegisterSkill(TEXT("Recognize"),    TEXT("Recognize"),     8, EPendragonSkillCategory::Civilian, true);

    // --- Compétences Ordinaires (Autres) ---
    RegisterSkill(TEXT("Hafted"),           TEXT("Hafted"),             7, EPendragonSkillCategory::Combat,   false);
    RegisterSkill(TEXT("Spear"),            TEXT("Spear"),              7, EPendragonSkillCategory::Combat,   false);
    RegisterSkill(TEXT("Two-Handed Hafted"),TEXT("Two-Handed Hafted"),  7, EPendragonSkillCategory::Combat,   false);
    RegisterSkill(TEXT("Bow"),              TEXT("Bow"),                7, EPendragonSkillCategory::Combat,   false);
    RegisterSkill(TEXT("Crossbow"),         TEXT("Crossbow"),           7, EPendragonSkillCategory::Combat,   false);
    RegisterSkill(TEXT("Thrown Weapon"),    TEXT("Thrown Weapon"),      7, EPendragonSkillCategory::Combat,   false);
    RegisterSkill(TEXT("Compose"),          TEXT("Compose"),            5, EPendragonSkillCategory::Civilian, false);
    RegisterSkill(TEXT("Dancing"),          TEXT("Dancing"),            5, EPendragonSkillCategory::Civilian, false);
    RegisterSkill(TEXT("Falconry"),         TEXT("Falconry"),           5, EPendragonSkillCategory::Civilian, false);
    RegisterSkill(TEXT("Fashion"),          TEXT("Fashion"),            5, EPendragonSkillCategory::Civilian, false);
    RegisterSkill(TEXT("Flirting"),         TEXT("Flirting"),           5, EPendragonSkillCategory::Civilian, false);
    RegisterSkill(TEXT("Folklore"),         TEXT("Folklore"),           5, EPendragonSkillCategory::Civilian, false);
    RegisterSkill(TEXT("Gaming"),           TEXT("Gaming"),             5, EPendragonSkillCategory::Civilian, false);
    RegisterSkill(TEXT("Intrigue"),         TEXT("Intrigue"),           5, EPendragonSkillCategory::Civilian, false);
    RegisterSkill(TEXT("Literacy"),         TEXT("Literacy"),           0, EPendragonSkillCategory::Civilian, false);
    RegisterSkill(TEXT("Orate"),            TEXT("Orate"),              5, EPendragonSkillCategory::Civilian, false);
    RegisterSkill(TEXT("Play Instrument"),  TEXT("Play Instrument"),    5, EPendragonSkillCategory::Civilian, false);
    RegisterSkill(TEXT("Religion"),         TEXT("Religion"),           5, EPendragonSkillCategory::Civilian, false);
    RegisterSkill(TEXT("Singing"),          TEXT("Singing"),            5, EPendragonSkillCategory::Civilian, false);
    RegisterSkill(TEXT("Stewardship"),      TEXT("Stewardship"),        8, EPendragonSkillCategory::Civilian, false);
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
