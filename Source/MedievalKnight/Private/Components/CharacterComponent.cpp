#include "MedievalKnight/Public/Components/CharacterComponent.h"

UCharacterComponent::UCharacterComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    
    // ==========================================
    // 0. DONNÉES DE TEST : TRAITS DE DÉPART
    // ==========================================
    Attributes.Size = 12;
    Attributes.Dexterity = 13;
    Attributes.Strength = 15;
    Attributes.Constitution = 13;
    Attributes.Appeal = 13;
    
    auto AddTraitPair = [this](ETrait Primary, ETrait Opposite, int32 DefaultVal = 10)
    {
        FTraitPair Pair;
        Pair.PrimaryTrait = Primary;
        Pair.OppositeTrait = Opposite;
        Pair.Value = DefaultVal;
        Traits.Add(Pair);
    };

    Traits.Empty();
    AddTraitPair(ETrait::Chaste,     ETrait::Lustful,     13);
    AddTraitPair(ETrait::Energetic,  ETrait::Lazy,        12);
    AddTraitPair(ETrait::Forgiving,  ETrait::Vengeful,    10);
    AddTraitPair(ETrait::Generous,   ETrait::Selfish,     11);
    AddTraitPair(ETrait::Honest,     ETrait::Deceitful,   12);
    AddTraitPair(ETrait::Just,       ETrait::Arbitrary,   14);
    AddTraitPair(ETrait::Merciful,   ETrait::Cruel,       10);
    AddTraitPair(ETrait::Modest,     ETrait::Proud,       10);
    AddTraitPair(ETrait::Spiritual,  ETrait::Worldly,     10);
    AddTraitPair(ETrait::Prudent,    ETrait::Reckless,    11);
    AddTraitPair(ETrait::Temperate,  ETrait::Indulgent,   10);
    AddTraitPair(ETrait::Trusting,   ETrait::Suspicious,  10);
    AddTraitPair(ETrait::Valorous,   ETrait::Cowardly,    15);
    
    // ==========================================
    // 1. DONNÉES DE TEST : PASSIONS DE DÉPART
    // ==========================================
    AddOrUpdatePassion(EPassionType::Loyalty,      TEXT("Lord"),       15);
    AddOrUpdatePassion(EPassionType::Duty,         TEXT("Vassalage"),  12);
    AddOrUpdatePassion(EPassionType::Love,         TEXT("Family"),     13);
    AddOrUpdatePassion(EPassionType::Hate,         TEXT("English"),    14);
    AddOrUpdatePassion(EPassionType::Hospitality,  TEXT("Realm"),      10);
    AddOrUpdatePassion(EPassionType::Devotion,     TEXT("Deity"),      5);
    AddOrUpdatePassion(EPassionType::Station,      TEXT("Personal"),   5);
    AddOrUpdatePassion(EPassionType::Honor,        TEXT("Personal"),   15);
    
    // ==========================================
    // 2. DONNÉES DE TEST : COMPÉTENCES DE DÉPART
    // ==========================================
    auto RegisterSkill = [this](FName ID, const FString& Name, int32 Val, ESkillCategory Cat, bool bKnightly)
    {
        FSkillData Skill;
        Skill.SkillID = ID;
        Skill.DisplayName = FText::FromString(Name);
        Skill.Value = Val;
        Skill.Category = Cat;
        Skill.bIsKnightlySkill = bKnightly;
        Skill.bCheckedForImprovement = false;
        CharacterSkills.Add(ID, Skill);
    };

    // --- Compétences de Chevalier : Combat ---
    RegisterSkill(TEXT("Battle"),       TEXT("Battle"),       10, ESkillCategory::Combat,   true);
    RegisterSkill(TEXT("Horsemanship"), TEXT("Horsemanship"), 15, ESkillCategory::Combat,   true);
    RegisterSkill(TEXT("Brawling"),     TEXT("Brawling"),     10, ESkillCategory::Combat,   true);
    RegisterSkill(TEXT("Charge"),       TEXT("Charge"),       13, ESkillCategory::Combat,   true);
    RegisterSkill(TEXT("Sword"),        TEXT("Sword"),        15, ESkillCategory::Combat,   true);

    // --- Compétences de Chevalier : Civiles / Non-Combat ---
    RegisterSkill(TEXT("Awareness"),    TEXT("Awareness"),    10, ESkillCategory::Civilian, true);
    RegisterSkill(TEXT("Courtesy"),     TEXT("Courtesy"),     12, ESkillCategory::Civilian, true);
    RegisterSkill(TEXT("FirstAid"),     TEXT("First Aid"),    10, ESkillCategory::Civilian, true);
    RegisterSkill(TEXT("Hunting"),      TEXT("Hunting"),      10, ESkillCategory::Civilian, true);
    RegisterSkill(TEXT("Recognize"),    TEXT("Recognize"),     8, ESkillCategory::Civilian, true);

    // --- Compétences Ordinaires (Autres) ---
    RegisterSkill(TEXT("Hafted"),           TEXT("Hafted"),             7, ESkillCategory::Combat,   false);
    RegisterSkill(TEXT("Spear"),            TEXT("Spear"),              7, ESkillCategory::Combat,   false);
    RegisterSkill(TEXT("Two-Handed Hafted"),TEXT("Two-Handed Hafted"),  7, ESkillCategory::Combat,   false);
    RegisterSkill(TEXT("Bow"),              TEXT("Bow"),                7, ESkillCategory::Combat,   false);
    RegisterSkill(TEXT("Crossbow"),         TEXT("Crossbow"),           7, ESkillCategory::Combat,   false);
    RegisterSkill(TEXT("Thrown Weapon"),    TEXT("Thrown Weapon"),      7, ESkillCategory::Combat,   false);
    RegisterSkill(TEXT("Compose"),          TEXT("Compose"),            5, ESkillCategory::Civilian, false);
    RegisterSkill(TEXT("Dancing"),          TEXT("Dancing"),            5, ESkillCategory::Civilian, false);
    RegisterSkill(TEXT("Falconry"),         TEXT("Falconry"),           5, ESkillCategory::Civilian, false);
    RegisterSkill(TEXT("Fashion"),          TEXT("Fashion"),            5, ESkillCategory::Civilian, false);
    RegisterSkill(TEXT("Flirting"),         TEXT("Flirting"),           5, ESkillCategory::Civilian, false);
    RegisterSkill(TEXT("Folklore"),         TEXT("Folklore"),           5, ESkillCategory::Civilian, false);
    RegisterSkill(TEXT("Gaming"),           TEXT("Gaming"),             5, ESkillCategory::Civilian, false);
    RegisterSkill(TEXT("Intrigue"),         TEXT("Intrigue"),           5, ESkillCategory::Civilian, false);
    RegisterSkill(TEXT("Literacy"),         TEXT("Literacy"),           0, ESkillCategory::Civilian, false);
    RegisterSkill(TEXT("Orate"),            TEXT("Orate"),              5, ESkillCategory::Civilian, false);
    RegisterSkill(TEXT("Play Instrument"),  TEXT("Play Instrument"),    5, ESkillCategory::Civilian, false);
    RegisterSkill(TEXT("Religion"),         TEXT("Religion"),           5, ESkillCategory::Civilian, false);
    RegisterSkill(TEXT("Singing"),          TEXT("Singing"),            5, ESkillCategory::Civilian, false);
    RegisterSkill(TEXT("Stewardship"),      TEXT("Stewardship"),        8, ESkillCategory::Civilian, false);
    
}

void UCharacterComponent::BeginPlay()
{
    Super::BeginPlay();

    // Ensure health is initialized properly on startup
    Attributes.CurrentHealth = Attributes.GetMaxHealth();
}

int32 UCharacterComponent::GetTraitValue(ETrait Trait, bool bIsPrimaryTrait) const
{
    for (const FTraitPair& Pair : Traits)
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

void UCharacterComponent::SetTraitValue(ETrait Trait, int32 NewValue)
{
    for (FTraitPair& Pair : Traits)
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

EDiceCheckResult UCharacterComponent::PerformD20Check(int32 TargetValue, int32& OutRoll)
{
    OutRoll = FMath::RandRange(1, 20);

    // Critical Success: Exact match to TargetValue, or 20 if TargetValue >= 20
    if ((OutRoll == TargetValue) || (TargetValue >= 20 && OutRoll == 20))
    {
        return EDiceCheckResult::CriticalSuccess;
    }

    // Fumble: Rolling 20 when TargetValue < 20
    if (OutRoll == 20 && TargetValue < 20)
    {
        return EDiceCheckResult::Fumble;
    }

    // Standard Success / Failure
    if (OutRoll <= TargetValue)
    {
        return EDiceCheckResult::Success;
    }

    return EDiceCheckResult::Failure;
}

EDiceCheckResult UCharacterComponent::CheckTrait(ETrait TraitPair, bool bCheckPrimary, int32& OutRoll) const
{
    int32 TargetVal = GetTraitValue(TraitPair, bCheckPrimary);
    return PerformD20Check(TargetVal, OutRoll);
}

void UCharacterComponent::AddOrUpdatePassion(EPassionType Type, const FString& Target, int32 Value)
{
    for (FPassion& Passion : Passions)
    {
        if (Passion.PassionType == Type && Passion.Target.Equals(Target, ESearchCase::IgnoreCase))
        {
            Passion.Value = FMath::Clamp(Value, 0, 20);
            return;
        }
    }

    FPassion NewPassion;
    NewPassion.PassionType = Type;
    NewPassion.Target = Target;
    NewPassion.Value = FMath::Clamp(Value, 0, 20);
    Passions.Add(NewPassion);
}

int32 UCharacterComponent::GetPassionValue(EPassionType Type, const FString& Target) const
{
    for (const FPassion& Passion : Passions)
    {
        if (Passion.PassionType == Type && Passion.Target.Equals(Target, ESearchCase::IgnoreCase))
        {
            return Passion.Value;
        }
    }
    return 0;
}

void UCharacterComponent::SetSkillValue(FName SkillID, int32 Value)
{
    if (FSkillData* Skill = CharacterSkills.Find(SkillID))
    {
        Skill->Value = FMath::Max(0, Value);
    }
    else
    {
        FSkillData NewSkill;
        NewSkill.SkillID = SkillID;
        NewSkill.DisplayName = FText::FromName(SkillID);
        NewSkill.Value = FMath::Max(0, Value);
        CharacterSkills.Add(SkillID, NewSkill);
    }
}

int32 UCharacterComponent::GetSkillValue(FName SkillID) const
{
    if (const FSkillData* Skill = CharacterSkills.Find(SkillID))
    {
        return Skill->Value;
    }
    return 0;
}

void UCharacterComponent::CheckSkillForImprovement(FName SkillID)
{
    if (FSkillData* Skill = CharacterSkills.Find(SkillID))
    {
        Skill->bCheckedForImprovement = true;
    }
}

void UCharacterComponent::CheckPassionForImprovement(EPassionType Type, const FString& Target)
{
    for (FPassion& Passion : Passions)
    {
        if (Passion.PassionType == Type && Passion.Target.Equals(Target, ESearchCase::IgnoreCase))
        {
            Passion.bCheckedForImprovement = true;
        }
    }
}

void UCharacterComponent::CheckTraitForImprovement(ETrait Trait, bool bIsPrimaryTrait)
{
    for (FTraitPair& Pair : Traits)
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

void UCharacterComponent::CheckAttributeForImprovement(EAttribute Attribute)
{
    switch (Attribute)
    {
    case EAttribute::Size:         Attributes.bSizeChecked = true; break;
    case EAttribute::Dexterity:    Attributes.bDexterityChecked = true; break;
    case EAttribute::Strength:     Attributes.bStrengthChecked = true; break;
    case EAttribute::Constitution: Attributes.bConstitutionChecked = true; break;
    case EAttribute::Appeal:       Attributes.bAppearanceChecked = true; break;
    }
}