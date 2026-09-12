#pragma once

#include "CoreMinimal.h"
#include "PendragonEnums.h"
#include "PendragonTypes.generated.h"

USTRUCT(BlueprintType)
struct FPendragonAttributes
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int32 Size = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int32 Dexterity = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int32 Strength = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int32 Constitution = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int32 Appearance = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|State")
	int32 CurrentHealth = 20;

	// Cases à cocher pour l'amélioration en phase d'hiver
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	bool bSizeChecked = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	bool bDexterityChecked = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	bool bStrengthChecked = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	bool bConstitutionChecked = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	bool bAppearanceChecked = false;

	// Derived Statistics (Getters)
	int32 GetKnockdown () const { return Size; }

	int32 GetDamageBonus() const { return RoundDivide(Size + Strength, 6); }

	int32 GetBrawlingDamage() const { return RoundDivide(Size + Strength, 6); }

	int32 GetMovementRate() const { return (RoundDivide(Strength + Dexterity, 2)+5); }

	int32 GetMajorWoundThreshold() const { return Constitution; }

	int32 GetHealRate() const { return FMath::Max(1, RoundDivide(Constitution, 5)); }
	
	int32 GetMaxHealth() const { return Constitution + Size; }

	int32 GetUnconscious() const { return RoundDivide(GetMaxHealth(),4); }

	static FORCEINLINE int32 RoundDivide(int32 Dividend, int32 Divisor)
	{
		if (Divisor == 0) return 0;
		return FMath::RoundToInt(static_cast<float>(Dividend) / static_cast<float>(Divisor));
	}
};

// Structure d'une Passion (ex: Loyalty (Lord) 15, Hate (Saxons) 12)
USTRUCT(BlueprintType)
struct FPendragonPassion
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Passion")
	EPendragonPassionType PassionType = EPendragonPassionType::Loyalty;

	// Cible de la passion (ex: "Lord Roderick", "Saxons", "Lady Ellen")
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Passion")
	FString Target;

	// Valeur actuelle (généralement entre 1 et 20, voire >20)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Passion")
	int32 Value = 10;

	// Case à cocher pour l'expérience en fin d'année
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Passion")
	bool bCheckedForImprovement = false;

	// Obtient automatiquement le groupe auquel appartient la passion
	EPendragonPassionGroup GetGroup() const
	{
		switch (PassionType)
		{
		case EPendragonPassionType::Duty:
		case EPendragonPassionType::Fealty:
		case EPendragonPassionType::Homage:
		case EPendragonPassionType::Loyalty:
			return EPendragonPassionGroup::Fidelitas;

		case EPendragonPassionType::Hate:
		case EPendragonPassionType::Love:
			return EPendragonPassionGroup::Fervor;

		case EPendragonPassionType::Adoration:
		case EPendragonPassionType::Devotion:
			return EPendragonPassionGroup::Adoratio;

		case EPendragonPassionType::Chivalry:
		case EPendragonPassionType::Hospitality:
		case EPendragonPassionType::Station:
			return EPendragonPassionGroup::Civilitas;

		default:
			return EPendragonPassionGroup::None;
		}
	}
	
	FText GetDisplayName() const
	{
		UEnum* EnumPtr = StaticEnum<EPendragonPassionType>();
		FString EnumName = EnumPtr ? EnumPtr->GetDisplayNameTextByValue(static_cast<int64>(PassionType)).ToString() : TEXT("Passion");
		return FText::FromString(FString::Printf(TEXT("%s (%s)"), *EnumName, *Target));
	}
};

// Structure d'une Compétence (ex: Horsemanship 15, Sword 13, Courtesy 10)
USTRUCT(BlueprintType)
struct FPendragonSkillData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
	FName SkillID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
	int32 Value = 5;
	
	// Catégorie : Combat ou Civile
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
	EPendragonSkillCategory Category = EPendragonSkillCategory::Civilian;
	
	// Est-ce une compétence de chevalier (ex: Épée, Lance, Équitation) ou de courtisan ?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
	bool bIsKnightlySkill = false;

	// Case à cocher pour progression
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
	bool bCheckedForImprovement = false;
};

USTRUCT(BlueprintType)
struct FPendragonTraitPair
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trait")
	EPendragonTrait PrimaryTrait = EPendragonTrait::Chaste;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trait")
	EPendragonTrait OppositeTrait = EPendragonTrait::Lustful;

	// Valeur du trait principal (0 à 20). Le trait opposé vaut toujours (20 - Value)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trait")
	int32 Value = 10;

	// Case à cocher pour la progression (phase d'hiver)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trait")
	bool bPrimaryCheckedForImprovement = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trait")
	bool bOppositeCheckedForImprovement = false;
};

/** Représente un lien familial ou féodal initial */
USTRUCT(BlueprintType)
struct FPendragonFamilyLink
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    FText RelationName = FText::FromString(TEXT("Père"));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    FText NPCName = FText::FromString(TEXT("Sir Elad"));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    FText RoleOrTitle = FText::FromString(TEXT("Seigneur de Vagon"));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    bool bIsAlive = true;
};

/** Données temporaires durant la création de personnage */
USTRUCT(BlueprintType)
struct FPendragonCreationData
{
    GENERATED_BODY()

    // Identity
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    FText CharacterName = FText::FromString(TEXT("Sir Gawain"));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    FText HomeCulture = FText::FromString(TEXT("Cymric"));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    FText Religion = FText::FromString(TEXT("Chrétien Britannique"));

    // Liens PNJ initiaux
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    TArray<FPendragonFamilyLink> FamilyLinks;

    // Pools de points disponibles à attribuer
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Points")
    int32 AttributePointsPool = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Points")
    int32 SkillPointsPool = 20;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Points")
    int32 PassionPointsPool = 15;

    // Attributs modifiés
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    FPendragonAttributes BaseAttributes;

    // Adjustements de Compétences (Nom -> Valeur attribuée)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills")
    TMap<FName, int32> SkillModifiers;

    // Adjustements de Passions (Nom -> Valeur attribuée)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Passions")
    TMap<FName, int32> PassionModifiers;
};