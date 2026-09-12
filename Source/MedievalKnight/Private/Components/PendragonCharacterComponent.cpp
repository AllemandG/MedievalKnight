#include "MedievalKnight/Public/Components/PendragonCharacterComponent.h"

UPendragonCharacterComponent::UPendragonCharacterComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    
    // ==========================================
    // 0. DONNÉES DE TEST : TRAITS DE DÉPART
    // ==========================================
    Attributes.Size = 12;
    Attributes.Dexterity = 13;
    Attributes.Strength = 15;
    Attributes.Constitution = 13;
    Attributes.Appearance = 13;
    
    auto AddTraitPair = [this](EPendragonTrait Primary, EPendragonTrait Opposite, int32 DefaultVal = 10)
    {
        FPendragonTraitPair Pair;
        Pair.PrimaryTrait = Primary;
        Pair.OppositeTrait = Opposite;
        Pair.Value = DefaultVal;
        Traits.Add(Pair);
    };

    Traits.Empty();
    AddTraitPair(EPendragonTrait::Chaste,     EPendragonTrait::Lustful,     13);
    AddTraitPair(EPendragonTrait::Energetic,  EPendragonTrait::Lazy,        12);
    AddTraitPair(EPendragonTrait::Forgiving,  EPendragonTrait::Vengeful,    10);
    AddTraitPair(EPendragonTrait::Generous,   EPendragonTrait::Selfish,     11);
    AddTraitPair(EPendragonTrait::Honest,     EPendragonTrait::Deceitful,   12);
    AddTraitPair(EPendragonTrait::Just,       EPendragonTrait::Arbitrary,   14);
    AddTraitPair(EPendragonTrait::Merciful,   EPendragonTrait::Cruel,       10);
    AddTraitPair(EPendragonTrait::Modest,     EPendragonTrait::Proud,       10);
    AddTraitPair(EPendragonTrait::Spiritual,  EPendragonTrait::Worldly,     10);
    AddTraitPair(EPendragonTrait::Prudent,    EPendragonTrait::Reckless,    11);
    AddTraitPair(EPendragonTrait::Temperate,  EPendragonTrait::Indulgent,   10);
    AddTraitPair(EPendragonTrait::Trusting,   EPendragonTrait::Suspicious,  10);
    AddTraitPair(EPendragonTrait::Valorous,   EPendragonTrait::Cowardly,    15);

    // ==========================================
    // 1. DONNÉES DE TEST : PASSIONS DE DÉPART
    // ==========================================
    AddOrUpdatePassion(EPendragonPassionType::Loyalty,      TEXT("Lord"),       15);
    AddOrUpdatePassion(EPendragonPassionType::Duty,         TEXT("Vassalage"),  12);
    AddOrUpdatePassion(EPendragonPassionType::Love,         TEXT("Family"),     13);
    AddOrUpdatePassion(EPendragonPassionType::Hate,         TEXT("English"),    14);
    AddOrUpdatePassion(EPendragonPassionType::Hospitality,  TEXT("Realm"),      10);
    AddOrUpdatePassion(EPendragonPassionType::Devotion,     TEXT("Deity"),      5);
    AddOrUpdatePassion(EPendragonPassionType::Station,      TEXT("Personal"),   5);
    AddOrUpdatePassion(EPendragonPassionType::Honor,        TEXT("Personal"),   15);

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

int32 UPendragonCharacterComponent::GetTraitValue(EPendragonTrait Trait, bool bIsPrimaryTrait) const
{
    for (const FPendragonTraitPair& Pair : Traits)
    {
        if (Pair.PrimaryTrait == Trait)
        {
            return bIsPrimaryTrait ? Pair.Value : (20 - Pair.Value);
        }
        if (Pair.OppositeTrait == Trait)
        {
            return bIsPrimaryTrait ? (20 - Pair.Value) : Pair.Value;
        }
    }
    return 10; // Valeur par défaut
}

void UPendragonCharacterComponent::SetTraitValue(EPendragonTrait Trait, int32 NewValue)
{
    for (FPendragonTraitPair& Pair : Traits)
    {
        if (Pair.PrimaryTrait == Trait)
        {
            Pair.Value = FMath::Clamp(NewValue, 0, 20);
            return;
        }
        if (Pair.OppositeTrait == Trait)
        {
            Pair.Value = FMath::Clamp(20 - NewValue, 0, 20);
            return;
        }
    }
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

void UPendragonCharacterComponent::CheckTraitForImprovement(EPendragonTrait Trait, bool bIsPrimaryTrait)
{
    for (FPendragonTraitPair& Pair : Traits)
    {
        if (Pair.PrimaryTrait == Trait)
        {
            if (bIsPrimaryTrait) Pair.bPrimaryCheckedForImprovement = true;
            else Pair.bOppositeCheckedForImprovement = true;
            return;
        }
        if (Pair.OppositeTrait == Trait)
        {
            if (bIsPrimaryTrait) Pair.bOppositeCheckedForImprovement = true;
            else Pair.bPrimaryCheckedForImprovement = true;
            return;
        }
    }
}

void UPendragonCharacterComponent::CheckAttributeForImprovement(EPendragonAttribute Attribute)
{
    switch (Attribute)
    {
    case EPendragonAttribute::Size:         Attributes.bSizeChecked = true; break;
    case EPendragonAttribute::Dexterity:    Attributes.bDexterityChecked = true; break;
    case EPendragonAttribute::Strength:     Attributes.bStrengthChecked = true; break;
    case EPendragonAttribute::Constitution: Attributes.bConstitutionChecked = true; break;
    case EPendragonAttribute::Appearance:   Attributes.bAppearanceChecked = true; break;
    }
}