// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/PendragonCharacterCreationSubsystem.h"

#include "Components/PendragonCharacterComponent.h"
#include "Components/PendragonInventoryComponent.h"

void UPendragonCharacterCreationSubsystem::StartNewCreation()
{
    CreationData = FPendragonCreationData();
    
    // Valeurs de base standard (6e édition)
    CreationData.BaseAttributes.Size = 10;
    CreationData.BaseAttributes.Dexterity = 10;
    CreationData.BaseAttributes.Strength = 10;
    CreationData.BaseAttributes.Constitution = 10;
    CreationData.BaseAttributes.Appearance = 10;
    
    CreationData.AttributePointsPool = 10;
    CreationData.SkillPointsPool = 20;
    CreationData.PassionPointsPool = 15;

    // Liens par défaut
    FPendragonFamilyLink Father;
    Father.RelationName = FText::FromString(TEXT("Père"));
    Father.NPCName = FText::FromString(TEXT("Sir Roderick"));
    Father.RoleOrTitle = FText::FromString(TEXT("Chevalier d'Elad"));
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
    else if (AttributeName == TEXT("Appearence") || AttributeName == TEXT("APP")) TargetAttr = &CreationData.BaseAttributes.Appearance;

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

void UPendragonCharacterCreationSubsystem::AddFamilyLink(const FPendragonFamilyLink& NewLink)
{
    CreationData.FamilyLinks.Add(NewLink);
    OnCreationDataChanged.Broadcast();
}

bool UPendragonCharacterCreationSubsystem::FinalizeCharacterCreation(UPendragonCharacterComponent* TargetCharacterComp, UPendragonInventoryComponent* TargetInventoryComp)
{
    if (!TargetCharacterComp) return false;

    // 1. Transfert des attributs de base
    TargetCharacterComp->Attributes = CreationData.BaseAttributes;

    // 2. Application des modificateurs de compétences
    for (const auto& KVP : CreationData.SkillModifiers)
    {
        int32 BaseVal = TargetCharacterComp->GetSkillValue(KVP.Key);
        TargetCharacterComp->SetSkillValue(KVP.Key, BaseVal + KVP.Value);
    }

    // 3. Équipement de départ de base si l'inventaire existe
    if (TargetInventoryComp)
    {
        // On assure que l'équipement de départ (Haubert de maille, Épée, Bouclier) est octroyé
        TargetInventoryComp->InitializeDefaultKnightEquipment();
    }

    return true;
}