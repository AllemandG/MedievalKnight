// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/PendragonCharacterCreationSubsystem.h"

#include "Components/PendragonCharacterComponent.h"
#include "Components/PendragonInventoryComponent.h"

void UPendragonCharacterCreationSubsystem::StartNewCreation()
{
    CreationData = FPendragonCreationData();

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
    auto AddTraitPair = [this](EPendragonTrait Primary, EPendragonTrait Opposite, int32 DefaultVal = 10)
    {
        FPendragonTraitPair Pair;
        Pair.PrimaryTrait = Primary;
        Pair.OppositeTrait = Opposite;
        Pair.Value = DefaultVal;
        CreationTraits.Add(Pair);
    };
    
    CreationTraits.Empty();
    AddTraitPair(EPendragonTrait::Chaste,     EPendragonTrait::Lustful,     10);
    AddTraitPair(EPendragonTrait::Energetic,  EPendragonTrait::Lazy,        10);
    AddTraitPair(EPendragonTrait::Forgiving,  EPendragonTrait::Vengeful,    10);
    AddTraitPair(EPendragonTrait::Generous,   EPendragonTrait::Selfish,     10);
    AddTraitPair(EPendragonTrait::Honest,     EPendragonTrait::Deceitful,   10);
    AddTraitPair(EPendragonTrait::Just,       EPendragonTrait::Arbitrary,   10);
    AddTraitPair(EPendragonTrait::Merciful,   EPendragonTrait::Cruel,       10);
    AddTraitPair(EPendragonTrait::Modest,     EPendragonTrait::Proud,       10);
    AddTraitPair(EPendragonTrait::Spiritual,  EPendragonTrait::Worldly,     10);
    AddTraitPair(EPendragonTrait::Prudent,    EPendragonTrait::Reckless,    10);
    AddTraitPair(EPendragonTrait::Temperate,  EPendragonTrait::Indulgent,   10);
    AddTraitPair(EPendragonTrait::Trusting,   EPendragonTrait::Suspicious,  10);
    AddTraitPair(EPendragonTrait::Valorous,   EPendragonTrait::Cowardly,    10);

    // Liens par défaut
    FPendragonFamilyLink Father;
    Father.RelationName = FText::FromString(TEXT("Father"));
    Father.NPCName = FText::FromString(TEXT("Henri de Latour"));
    Father.RoleOrTitle = FText::FromString(TEXT("Knight"));
    Father.bIsAlive = true;
    CreationData.FamilyLinks.Add(Father);

    OnCreationDataChanged.Broadcast();
}

bool UPendragonCharacterCreationSubsystem::ModifyAttribute(FName AttributeName, int32 Delta)
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

bool UPendragonCharacterCreationSubsystem::ModifySkill(FName SkillName, int32 Delta)
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

bool UPendragonCharacterCreationSubsystem::ModifyTrait(EPendragonTrait PrimaryTrait, int32 Delta)
{
    if (Delta == 0) return false;

    for (FPendragonTraitPair& Pair : CreationTraits)
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

bool UPendragonCharacterCreationSubsystem::ModifyPassion(FName PassionName, int32 Delta)
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

bool UPendragonCharacterCreationSubsystem::ApplyAttributeAugmentation(EPendragonAttribute Attribute)
{
    if (RemainingAugmentationChoices <= 0) return false;

    switch (Attribute)
    {
    case EPendragonAttribute::Size:
        CreationData.BaseAttributes.Size += 1;
        break;
    case EPendragonAttribute::Dexterity:
        CreationData.BaseAttributes.Dexterity += 1;
        break;
    case EPendragonAttribute::Strength:
        CreationData.BaseAttributes.Strength += 1;
        break;
    case EPendragonAttribute::Constitution:
        CreationData.BaseAttributes.Constitution += 1;
        break;
    default:
        return false;
    }

    RemainingAugmentationChoices--;
    OnCreationDataChanged.Broadcast();
    return true;
}

bool UPendragonCharacterCreationSubsystem::ApplySkillPointsAugmentation()
{
    if (RemainingAugmentationChoices <= 0) return false;

    // Ajoute +6 au pool de points de compétences distribuables
    CreationData.SkillPointsPool += 6;

    RemainingAugmentationChoices--;
    OnCreationDataChanged.Broadcast();
    return true;
}

void UPendragonCharacterCreationSubsystem::ApplyFamilyBonus(FName SkillName, int32 BonusAmount)
{
    int32 CurrentVal = CreationData.SkillModifiers.FindRef(SkillName);
    CreationData.SkillModifiers.Add(SkillName, CurrentVal + BonusAmount);

    OnCreationDataChanged.Broadcast();
}

void UPendragonCharacterCreationSubsystem::GenerateParentHistory()
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

int32 UPendragonCharacterCreationSubsystem::GetChivalryTraitsSum() const
{
    int32 Sum = 0;
    const TArray<EPendragonTrait> ChivalryTraits = {
        EPendragonTrait::Energetic,
        EPendragonTrait::Generous,
        EPendragonTrait::Just,
        EPendragonTrait::Merciful,
        EPendragonTrait::Modest,
        EPendragonTrait::Valorous
    };

    for (const FPendragonTraitPair& Pair : CreationTraits)
    {
        if (ChivalryTraits.Contains(Pair.PrimaryTrait))
        {
            Sum += Pair.Value;
        }
    }
    return Sum;
}

bool UPendragonCharacterCreationSubsystem::IsEligibleForReligiousBonus() const
{
    // Christianisme médiéval : Chaste, Generous, Merciful, Modest, Temperate à 16+
    const TArray<EPendragonTrait> ChristianTraits = {
        EPendragonTrait::Chaste,
        EPendragonTrait::Generous,
        EPendragonTrait::Merciful,
        EPendragonTrait::Modest,
        EPendragonTrait::Temperate
    };

    for (const FPendragonTraitPair& Pair : CreationTraits)
    {
        if (ChristianTraits.Contains(Pair.PrimaryTrait))
        {
            if (Pair.Value < 16) return false;
        }
    }
    return true;
}

void UPendragonCharacterCreationSubsystem::AddFamilyLink(const FPendragonFamilyLink& NewLink)
{
    CreationData.FamilyLinks.Add(NewLink);
    OnCreationDataChanged.Broadcast();
}

bool UPendragonCharacterCreationSubsystem::FinalizeCharacterCreation(UPendragonCharacterComponent* TargetCharacterComp, UPendragonInventoryComponent* TargetInventoryComp)
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