#pragma once

#include "CoreMinimal.h"
#include "MedievalKnight/Public/Core/PendragonEnums.h"
#include "StoryTypes.generated.h"

class UStoryNodeDataAsset;

UENUM(BlueprintType)
enum class ERequirementType : uint8
{
    Trait,
    Attribute,
    Skill,
    Passion
};

UENUM(BlueprintType)
enum class EEffectType : uint8
{
    ModifyTrait,
    ModifyHealth,
    ModifySkill,
    ModifyPassion
};

// Structure représentant une condition pour débloquer ou réussir un choix
USTRUCT(BlueprintType)
struct FPendragonRequirement
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Requirement")
    ERequirementType RequirementType = ERequirementType::Trait;

    // Utilisé si RequirementType est Trait
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Requirement", meta = (EditCondition = "RequirementType == ERequirementType::Trait", EditConditionHides))
    EPendragonTrait Trait = EPendragonTrait::Valiant_Cowardly;

    // Indique si la condition porte sur le trait primaire (ex: Valiant) ou secondaire (ex: Cowardly)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Requirement", meta = (EditCondition = "RequirementType == ERequirementType::Trait", EditConditionHides))
    bool bCheckPrimaryTrait = true;

    // Utilisé pour les Compétences ou Passions (ex: "Jousting", "Honor")
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Requirement", meta = (EditCondition = "RequirementType == ERequirementType::Skill || RequirementType == ERequirementType::Passion", EditConditionHides))
    FName Name = NAME_None;

    // Valeur minimale requise
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Requirement")
    int32 MinimumValue = 10;
};

// Structure représentant l'effet/conséquence d'un choix
USTRUCT(BlueprintType)
struct FPendragonEffect
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect")
    EEffectType EffectType = EEffectType::ModifyTrait;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect", meta = (EditCondition = "EffectType == EEffectType::ModifyTrait", EditConditionHides))
    EPendragonTrait Trait = EPendragonTrait::Valiant_Cowardly;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect", meta = (EditCondition = "EffectType == EEffectType::ModifySkill || EffectType == EEffectType::ModifyPassion", EditConditionHides))
    FName Name = NAME_None;

    // Quantité à ajouter ou soustraire (peut être négative)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect")
    int32 ModifierValue = 0;
};

// Structure d'un choix offert au joueur
USTRUCT(BlueprintType)
struct FStoryChoice
{
    GENERATED_BODY()

    // Texte affiché sur le bouton de choix (ex: "Charger la ligne ennemie à cheval")
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Choice", meta = (MultiLine = true))
    FText ChoiceText;

    // Conditions requises pour que ce choix soit disponible (optionnel)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Choice")
    TArray<FPendragonRequirement> Requirements;

    // Indique si ce choix nécessite de lancer un d20
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Choice|Check")
    bool bRequiresCheck = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Choice|Check", meta = (EditCondition = "bRequiresCheck", EditConditionHides))
    ERequirementType CheckType = ERequirementType::Trait;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Choice|Check", meta = (EditCondition = "bRequiresCheck && CheckType == ERequirementType::Trait", EditConditionHides))
    EPendragonTrait CheckTrait = EPendragonTrait::Valiant_Cowardly;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Choice|Check", meta = (EditCondition = "bRequiresCheck && CheckType == ERequirementType::Trait", EditConditionHides))
    bool bCheckPrimaryTrait = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Choice|Check", meta = (EditCondition = "bRequiresCheck && (CheckType == ERequirementType::Skill || CheckType == ERequirementType::Passion)", EditConditionHides))
    FName CheckName = NAME_None;

    // Effets appliqués directement si aucun test de d20 n'est requis
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Choice|Outcome", meta = (EditCondition = "!bRequiresCheck", EditConditionHides))
    TArray<FPendragonEffect> DirectEffects;

    // Nœud suivant si aucun test de d20 ou si transition directe
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Choice|Outcome", meta = (EditCondition = "!bRequiresCheck", EditConditionHides))
    TSoftObjectPtr<UStoryNodeDataAsset> NextNode;

    // Redirections en cas de test de d20
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Choice|Outcome|CheckResults", meta = (EditCondition = "bRequiresCheck", EditConditionHides))
    TSoftObjectPtr<UStoryNodeDataAsset> SuccessNode;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Choice|Outcome|CheckResults", meta = (EditCondition = "bRequiresCheck", EditConditionHides))
    TSoftObjectPtr<UStoryNodeDataAsset> CriticalSuccessNode;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Choice|Outcome|CheckResults", meta = (EditCondition = "bRequiresCheck", EditConditionHides))
    TSoftObjectPtr<UStoryNodeDataAsset> FailureNode;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Choice|Outcome|CheckResults", meta = (EditCondition = "bRequiresCheck", EditConditionHides))
    TSoftObjectPtr<UStoryNodeDataAsset> FumbleNode;
};