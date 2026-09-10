#pragma once

#include "CoreMinimal.h"
#include "PendragonTypes.generated.h"

USTRUCT(BlueprintType)
struct FPendragonAttributes
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int32 Size = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int32 Strength = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int32 Dexterity = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int32 Constitution = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int32 Appearance = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|State")
	int32 CurrentHealth = 20;

	// Derived Statistics (Getters)
	int32 GetMaxHealth() const
	{
		return Size + Constitution;
	}

	int32 GetMajorWoundThreshold() const
	{
		return Constitution;
	}

	int32 GetHealRate() const
	{
		return FMath::Max(1, Constitution / 5);
	}

	int32 GetDamageBonus() const
	{
		return (Strength + Size) / 6;
	}
};

// Types de Passions dans Pendragon
UENUM(BlueprintType)
enum class EPendragonPassionGroup : uint8
{
	None        UMETA(DisplayName = "None / Individual"),
	Fidelitas   UMETA(DisplayName = "Fidelitas"),
	Fervor      UMETA(DisplayName = "Fervor"),
	Adoratio    UMETA(DisplayName = "Adoratio"),
	Civilitas   UMETA(DisplayName = "Civilitas")
};

UENUM(BlueprintType)
enum class EPendragonPassionType : uint8
{
	// Fidelitas
	Duty        UMETA(DisplayName = "Duty"),
	Fealty      UMETA(DisplayName = "Fealty"),
	Homage      UMETA(DisplayName = "Homage"),
	Loyalty     UMETA(DisplayName = "Loyalty"),

	// Fervor
	Hate        UMETA(DisplayName = "Hate"),
	Love        UMETA(DisplayName = "Love"),

	// Adoratio
	Adoration   UMETA(DisplayName = "Adoration"),
	Devotion    UMETA(DisplayName = "Devotion"),

	// Civilitas
	Chivalry    UMETA(DisplayName = "Chivalry"),
	Hospitality UMETA(DisplayName = "Hospitality"),
	Station     UMETA(DisplayName = "Station"),

	// Indépendant
	Honor       UMETA(DisplayName = "Honor"),
	Avarice     UMETA(DisplayName = "Avarice"),
	Fear        UMETA(DisplayName = "Fear"),
	Jealousy	UMETA(DisplayName = "Jealousy")
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

	// Est-ce une compétence de chevalier (ex: Épée, Lance, Équitation) ou de courtisan ?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
	bool bIsKnightlySkill = false;

	// Case à cocher pour progression
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
	bool bCheckedForImprovement = false;
};