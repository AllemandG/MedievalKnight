#pragma once

#include "CoreMinimal.h"
#include "MedievalKnightEnums.h"
#include "MedievalKnightTypes.generated.h"

USTRUCT(BlueprintType)
struct FAttributes
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
	int32 Appeal = 10;

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

USTRUCT(BlueprintType)
struct FCharacterOrigin
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Origins")
	ECulture Culture = ECulture::French;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Origins")
	ELocalCulture LocalCulture = ELocalCulture::Aquitaine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Origins")
	EReligion Religion = EReligion::Christian;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Origins")
	int32 BirthYear = 1312;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Origins")
	bool NobleBlood = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Origins")
	bool Heir = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Origins")
	EHairColor HairColor = EHairColor::Brown;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Origins")
	EEyeColor EyeColor = EEyeColor::LightBrown;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Origins")
	TArray<EDistinctiveFeatures> DistinctiveFeatures;
};

// Structure d'une Passion (ex: Loyalty (Lord) 15, Hate (Saxons) 12)
USTRUCT(BlueprintType)
struct FPassion
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Passion")
	EPassionType PassionType = EPassionType::Loyalty;

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
	EPassionGroup GetGroup() const
	{
		switch (PassionType)
		{
		case EPassionType::Duty:
		case EPassionType::Fealty:
		case EPassionType::Homage:
		case EPassionType::Loyalty:
			return EPassionGroup::Fidelitas;

		case EPassionType::Hate:
		case EPassionType::Love:
			return EPassionGroup::Fervor;

		case EPassionType::Adoration:
		case EPassionType::Devotion:
			return EPassionGroup::Adoratio;

		case EPassionType::Chivalry:
		case EPassionType::Hospitality:
		case EPassionType::Station:
			return EPassionGroup::Civilitas;

		default:
			return EPassionGroup::None;
		}
	}
	
	FText GetDisplayName() const
	{
		UEnum* EnumPtr = StaticEnum<EPassionType>();
		FString EnumName = EnumPtr ? EnumPtr->GetDisplayNameTextByValue(static_cast<int64>(PassionType)).ToString() : TEXT("Passion");
		return FText::FromString(FString::Printf(TEXT("%s (%s)"), *EnumName, *Target));
	}
};

// Structure d'une Compétence (ex: Horsemanship 15, Sword 13, Courtesy 10)
USTRUCT(BlueprintType)
struct FSkillData
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
	ESkillCategory Category = ESkillCategory::Civilian;
	
	// Est-ce une compétence de chevalier (ex: Épée, Lance, Équitation) ou de courtisan ?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
	bool bIsKnightlySkill = false;

	// Case à cocher pour progression
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skill")
	bool bCheckedForImprovement = false;
};

USTRUCT(BlueprintType)
struct FTraitPair
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trait")
	ETrait PrimaryTrait = ETrait::Chaste;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trait")
	ETrait OppositeTrait = ETrait::Lustful;

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
struct FFamilyLink
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    FText RelationName = FText::FromString(TEXT("Father"));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    FText NPCName = FText::FromString(TEXT("Henri de Latour"));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    FText RoleOrTitle = FText::FromString(TEXT("Knight"));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    bool bIsAlive = true;
};

USTRUCT(BlueprintType)
struct FHeraldry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Heraldry")
	FText ShieldDescription = FText::FromString(TEXT("The shield has an Azure and Argent chequey pattern with an Argent Tower charge.")); // Description textuelle ou blasonnement

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Heraldry")
	FText PrimaryColor = FText::FromString(TEXT("Silver"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Heraldry")
	FText SecondaryColor = FText::FromString(TEXT("Azur"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Heraldry")
	FText ChargeEmblem = FText::FromString(TEXT("Cross"));
};

USTRUCT(BlueprintType)
struct FParentHistory
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "History")
	FText FatherName = FText::FromString(TEXT("Henri de Latour"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "History")
	int32 FatherBirthYear = 1287;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "History")
	int32 InheritedGlory = 100; // Gloire transmise par le père

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "History")
	FText FamilyCharacteristic = FText::FromString(TEXT("Size Bonus (+3) or Bloodline Proficiency"));
};

USTRUCT(BlueprintType)
struct FAppearanceDetails
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
	FText DistinctiveFeatures = FText::FromString(TEXT("Chin scar, piercing gaze"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
	FText HairAndEyes = FText::FromString(TEXT("Brown hair, hazel eyes"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
	FText HeightAndWeight = FText::FromString(TEXT("1m80, 82 kg"));
};

/** Données temporaires durant la création de personnage */
USTRUCT(BlueprintType)
struct FCreationData
{
	GENERATED_BODY()

	// Identity
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
	FText FirstName = FText::FromString(TEXT("Guislain"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
	FText LastName = FText::FromString(TEXT("de Latour"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
	FText HomeCulture = FText::FromString(TEXT("French"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
	FText Religion = FText::FromString(TEXT("Christian"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
	FHeraldry Heraldry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
	FAppearanceDetails Appearance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
	FParentHistory ParentHistory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
	int32 Glory = 1000;

	// Liens PNJ initiaux
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
	TArray<FFamilyLink> FamilyLinks;

	// Pools de points disponibles à attribuer
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Points")
	int32 AttributePointsPool = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Points")
	int32 SkillPointsPool = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Points")
	int32 PassionPointsPool = 15;

	// Attributs modifiés
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FAttributes BaseAttributes;

	// Adjustements de Compétences (Nom -> Valeur attribuée)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills")
	TMap<FName, int32> SkillModifiers;

	// Adjustements de Passions (Nom -> Valeur attribuée)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Passions")
	TMap<FName, int32> PassionModifiers;
};