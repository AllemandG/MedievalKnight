// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/MedievalCharacterCreationSubsystem.h"

#include "Components/CharacterComponent.h"
#include "Components/InventoryComponent.h"

void UMedievalCharacterCreationSubsystem::StartNewCreation()
{
    CreationData = FCreationData();

    // Valeurs par défaut adaptées à la Guerre de Cent Ans
    CreationData.FirstName = FText::FromString(TEXT("Guislain"));
    CreationData.LastName = FText::FromString(TEXT("de Latour"));
    CreationData.HomeCulture = FText::FromString(TEXT("French"));
    CreationData.Religion = FText::FromString(TEXT("Christian"));
    
    // Valeurs de base standard (6e édition)
    CreationData.BaseAttributes.Size = 10;
    CreationData.BaseAttributes.Dexterity = 10;
    CreationData.BaseAttributes.Strength = 10;
    CreationData.BaseAttributes.Constitution = 10;
    CreationData.BaseAttributes.Appeal = 10;
    
    CreationData.AttributePointsPool = 10;
    CreationData.SkillPointsPool = 20;
    CreationData.PassionPointsPool = 15;

    // Initialisation des 13 paires de traits par défaut (valeurs neutres à 10)
    auto AddTraitPair = [this](ETrait Primary, ETrait Opposite, int32 DefaultVal = 10)
    {
        FTraitPair Pair;
        Pair.PrimaryTrait = Primary;
        Pair.OppositeTrait = Opposite;
        Pair.Value = DefaultVal;
        CreationTraits.Add(Pair);
    };
    
    CreationTraits.Empty();
    AddTraitPair(ETrait::Chaste,     ETrait::Lustful,     10);
    AddTraitPair(ETrait::Energetic,  ETrait::Lazy,        10);
    AddTraitPair(ETrait::Forgiving,  ETrait::Vengeful,    10);
    AddTraitPair(ETrait::Generous,   ETrait::Selfish,     10);
    AddTraitPair(ETrait::Honest,     ETrait::Deceitful,   10);
    AddTraitPair(ETrait::Just,       ETrait::Arbitrary,   10);
    AddTraitPair(ETrait::Merciful,   ETrait::Cruel,       10);
    AddTraitPair(ETrait::Modest,     ETrait::Proud,       10);
    AddTraitPair(ETrait::Spiritual,  ETrait::Worldly,     10);
    AddTraitPair(ETrait::Prudent,    ETrait::Reckless,    10);
    AddTraitPair(ETrait::Temperate,  ETrait::Indulgent,   10);
    AddTraitPair(ETrait::Trusting,   ETrait::Suspicious,  10);
    AddTraitPair(ETrait::Valorous,   ETrait::Cowardly,    10);

    // Liens par défaut
    FFamilyLink Father;
    Father.RelationName = FText::FromString(TEXT("Father"));
    Father.NPCName = FText::FromString(TEXT("Henri de Latour"));
    Father.RoleOrTitle = FText::FromString(TEXT("Knight"));
    Father.bIsAlive = true;
    CreationData.FamilyLinks.Add(Father);

    OnCreationDataChanged.Broadcast();
}

bool UMedievalCharacterCreationSubsystem::ModifyAttribute(FName AttributeName, int32 Delta)
{
    if (Delta == 0) return false;

    // Augmentation : vérification des points disponibles
    if (Delta > 0 && CreationData.AttributePointsPool < Delta) return false;

    int32* TargetAttr = nullptr;
    if (AttributeName == TEXT("Size") || AttributeName == TEXT("SIZ")) TargetAttr = &CreationData.BaseAttributes.Size;
    else if (AttributeName == TEXT("Dexterity") || AttributeName == TEXT("DEX")) TargetAttr = &CreationData.BaseAttributes.Dexterity;
    else if (AttributeName == TEXT("Strength") || AttributeName == TEXT("STR")) TargetAttr = &CreationData.BaseAttributes.Strength;
    else if (AttributeName == TEXT("Constitution") || AttributeName == TEXT("CON")) TargetAttr = &CreationData.BaseAttributes.Constitution;
    else if (AttributeName == TEXT("Appeal") || AttributeName == TEXT("APP")) TargetAttr = &CreationData.BaseAttributes.Appeal;

    if (!TargetAttr) return false;

    // Empêcher d'abaisser un attribut sous sa valeur de base (10)
    if (*TargetAttr + Delta < 10) return false;

    *TargetAttr += Delta;
    CreationData.AttributePointsPool -= Delta;

    OnCreationDataChanged.Broadcast();
    return true;
}

bool UMedievalCharacterCreationSubsystem::ModifySkill(FName SkillName, int32 Delta)
{
    if (Delta == 0) return false;
    if (Delta > 0 && CreationData.SkillPointsPool < Delta) return false;

    int32 CurrentVal = CreationData.SkillModifiers.FindRef(SkillName);
    if (CurrentVal + Delta < 0) return false;

    CreationData.SkillModifiers.Add(SkillName, CurrentVal + Delta);
    CreationData.SkillPointsPool -= Delta;

    OnCreationDataChanged.Broadcast();
    return true;
}

bool UMedievalCharacterCreationSubsystem::ModifyTrait(ETrait PrimaryTrait, int32 Delta)
{
    if (Delta == 0) return false;

    for (FTraitPair& Pair : CreationTraits)
    {
        if (Pair.PrimaryTrait == PrimaryTrait)
        {
            int32 NewVal = Pair.Value + Delta;
            if (NewVal < 1 || NewVal > 19) return false;

            Pair.Value = NewVal;
            OnCreationDataChanged.Broadcast();
            return true;
        }
    }
    return false;
}

bool UMedievalCharacterCreationSubsystem::ModifyPassion(FName PassionName, int32 Delta)
{
    if (Delta == 0) return false;
    if (Delta > 0 && CreationData.PassionPointsPool < Delta) return false;

    int32 CurrentVal = CreationData.PassionModifiers.FindRef(PassionName);
    if (CurrentVal + Delta < 0) return false;

    CreationData.PassionModifiers.Add(PassionName, CurrentVal + Delta);
    CreationData.PassionPointsPool -= Delta;

    OnCreationDataChanged.Broadcast();
    return true;
}

bool UMedievalCharacterCreationSubsystem::ApplyAttributeAugmentation(EAttribute Attribute)
{
    if (RemainingAugmentationChoices <= 0) return false;

    switch (Attribute)
    {
    case EAttribute::Size:
        CreationData.BaseAttributes.Size += 1;
        break;
    case EAttribute::Dexterity:
        CreationData.BaseAttributes.Dexterity += 1;
        break;
    case EAttribute::Strength:
        CreationData.BaseAttributes.Strength += 1;
        break;
    case EAttribute::Constitution:
        CreationData.BaseAttributes.Constitution += 1;
        break;
    default:
        return false;
    }

    RemainingAugmentationChoices--;
    OnCreationDataChanged.Broadcast();
    return true;
}

bool UMedievalCharacterCreationSubsystem::ApplySkillPointsAugmentation()
{
    if (RemainingAugmentationChoices <= 0) return false;

    // Ajoute +6 au pool de points de compétences distribuables
    CreationData.SkillPointsPool += 6;

    RemainingAugmentationChoices--;
    OnCreationDataChanged.Broadcast();
    return true;
}

void UMedievalCharacterCreationSubsystem::ApplyFamilyBonus(FName SkillName, int32 BonusAmount)
{
    int32 CurrentVal = CreationData.SkillModifiers.FindRef(SkillName);
    CreationData.SkillModifiers.Add(SkillName, CurrentVal + BonusAmount);

    OnCreationDataChanged.Broadcast();
}

void UMedievalCharacterCreationSubsystem::GenerateParentHistory()
{
    // Exemple de génération rapide d'historique (Guerre de Cent Ans)
    CreationData.ParentHistory.FatherName = FText::FromString(TEXT("Henri de Latour"));
    CreationData.ParentHistory.FatherBirthYear = 1287;
    
    // Tirage / Calcul de la Gloire héritée (1/10 de la gloire du père, ex: 100 à 300)
    int32 FatherGloryAt14 = 2000 + 100 * FMath::RandRange(6, 36);
    CreationData.ParentHistory.InheritedGlory = FatherGloryAt14 / 4;
    
    // Intégration de la gloire héritée au personnage
    CreationData.Glory = 1000 + CreationData.ParentHistory.InheritedGlory;

    OnCreationDataChanged.Broadcast();
}

int32 UMedievalCharacterCreationSubsystem::GetChivalryTraitsSum() const
{
    int32 Sum = 0;
    const TArray<ETrait> ChivalryTraits = {
        ETrait::Energetic,
        ETrait::Generous,
        ETrait::Just,
        ETrait::Merciful,
        ETrait::Modest,
        ETrait::Valorous
    };

    for (const FTraitPair& Pair : CreationTraits)
    {
        if (ChivalryTraits.Contains(Pair.PrimaryTrait))
        {
            Sum += Pair.Value;
        }
    }
    return Sum;
}

bool UMedievalCharacterCreationSubsystem::IsEligibleForReligiousBonus() const
{
    // Christianisme médiéval : Chaste, Generous, Merciful, Modest, Temperate à 16+
    const TArray<ETrait> ChristianTraits = {
        ETrait::Chaste,
        ETrait::Generous,
        ETrait::Merciful,
        ETrait::Modest,
        ETrait::Temperate
    };

    for (const FTraitPair& Pair : CreationTraits)
    {
        if (ChristianTraits.Contains(Pair.PrimaryTrait))
        {
            if (Pair.Value < 16) return false;
        }
    }
    return true;
}

void UMedievalCharacterCreationSubsystem::AddFamilyLink(const FFamilyLink& NewLink)
{
    CreationData.FamilyLinks.Add(NewLink);
    OnCreationDataChanged.Broadcast();
}

bool UMedievalCharacterCreationSubsystem::FinalizeCharacterCreation(UCharacterComponent* TargetCharacterComp, UInventoryComponent* TargetInventoryComp)
{
    if (!TargetCharacterComp) return false;

    // 1. Transfert des données d'identité & lignage
    TargetCharacterComp->FirstName = CreationData.FirstName;
    TargetCharacterComp->LastName = CreationData.LastName;
    TargetCharacterComp->HomeCulture = CreationData.HomeCulture;
    TargetCharacterComp->Religion = CreationData.Religion;
    TargetCharacterComp->FamilyLinks = CreationData.FamilyLinks;
    TargetCharacterComp->BirthYear = 1312; // ex: 20 ans en 1332

    // Héraldique & Apparence
    TargetCharacterComp->Heraldry = CreationData.Heraldry;
    TargetCharacterComp->Appearance = CreationData.Appearance;
    TargetCharacterComp->ParentHistory = CreationData.ParentHistory;
    TargetCharacterComp->Glory = CreationData.Glory;

    // 2. Transfert des attributs & traits
    TargetCharacterComp->Attributes = CreationData.BaseAttributes;
    TargetCharacterComp->Traits = CreationTraits;

    // 3. Application des compétences
    for (const auto& KVP : CreationData.SkillModifiers)
    {
        int32 BaseVal = TargetCharacterComp->GetSkillValue(KVP.Key);
        TargetCharacterComp->SetSkillValue(KVP.Key, BaseVal + KVP.Value);
    }

    // 4. Équipement de départ de base si l'inventaire existe
    if (TargetInventoryComp)
    {
        // On assure que l'équipement de départ (Haubert de maille, Épée, Bouclier) est octroyé
        TargetInventoryComp->InitializeDefaultKnightEquipment();
    }

    return true;
}