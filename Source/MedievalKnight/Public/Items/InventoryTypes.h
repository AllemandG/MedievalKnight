#pragma once

#include "CoreMinimal.h"
#include "Core/PendragonTypes.h"
#include "InventoryTypes.generated.h"



USTRUCT(BlueprintType)
struct FPendragonItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ItemID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FText ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EItemType ItemType = EItemType::General;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EEquipmentSlot Slot = EEquipmentSlot::None;

	// Valeur financière en Deniers / Sous
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Economy")
	int32 ValueInDenarii = 0;

	// Quantité
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 Quantity = 1;
};

USTRUCT(BlueprintType)
struct FWeapon : public FPendragonItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon", meta = (EditCondition = "ItemType == EItemType::Weapon", EditConditionHides))
	EWeaponType WeaponType = EWeaponType::Sword;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon", meta = (EditCondition = "WeaponType == EWeaponType::Thrown", EditConditionHides))
	EWeaponType WeaponAltType = EWeaponType::Spear;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon", meta = (EditCondition = "ItemType == EItemType::Weapon", EditConditionHides))
	EWeaponSubType WeaponSubType = EWeaponSubType::ArmingSword;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon)", meta = (EditCondition = "ItemType == EItemType::Weapon", EditConditionHides))
	EFootMountedType FootMountedType = EFootMountedType::Foot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon)", meta = (EditCondition = "WeaponType == EWeaponType::Bow || WeaponType == EWeaponType::Crossbow || WeaponType == EWeaponType::Thrown", EditConditionHides))
	ERange Range = ERange::Medium;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon", meta = (EditCondition = "ItemType == EItemType::Weapon", EditConditionHides))
	bool TwoHanded = false;

	// Statistiques d'équipement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Stats", meta = (EditCondition = "ItemType == EItemType::Weapon", EditConditionHides))
	int32 BonusDamage = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Stats", meta = (EditCondition = "WeaponType == EWeaponType::Thrown", EditConditionHides))
	int32 BonusThrown = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Stats", meta = (EditCondition = "ItemType == EItemType::Weapon", EditConditionHides))
	int32 FlatDamage = 0;
};

USTRUCT(BlueprintType)
struct FArmor : public FPendragonItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Armor", meta = (EditCondition = "ItemType == EItemType::Armor", EditConditionHides))
	EArmorType ArmorType = EArmorType::Textile;

	// Statistiques d'équipement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Stats", meta = (EditCondition = "ItemType == EItemType::Armor || ItemType == EItemType::Shield", EditConditionHides))
	int32 ArmorProtection = 0;
};

USTRUCT(BlueprintType)
struct FShield : public FPendragonItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Shield", meta = (EditCondition = "ItemType == EItemType::Shield", EditConditionHides))
	EShieldType ShieldType = EShieldType::Medium;

	// Statistiques d'équipement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Stats", meta = (EditCondition = "ItemType == EItemType::Armor || ItemType == EItemType::Shield", EditConditionHides))
	int32 ArmorProtection = 0;
};

USTRUCT(BlueprintType)
struct FHorseArmor : public FPendragonItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|HorseArmor")
	EHorseArmorType HorseArmorType = EHorseArmorType::CaparisonOpen;

	// Statistiques d'équipement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Stats", meta = (EditCondition = "ItemType == EItemType::HorseArmor", EditConditionHides))
	int32 ArmorProtection = 0;
};

USTRUCT(BlueprintType)
struct FHorse : public FPendragonItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse", meta = (EditCondition = "ItemType == EItemType::Mount", EditConditionHides))
	EHorseType HorseType = EHorseType::Combat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse", meta = (EditCondition = "ItemType == EItemType::Mount", EditConditionHides))
	EHorseSubType HorseSubType = EHorseSubType::Charger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	int32 Size = 40;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	int32 Dexterity = 13;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	int32 Strength = 32;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	int32 Constitution = 15;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	int32 Move = 16;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	int32 HP = 55;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	int32 NormalDamage = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	int32 ChargeDamage = 6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	FHorseArmor Caparison;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	FHorseArmor HorseArmor;

	// Statistiques d'équipement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Stats", meta = (EditCondition = "ItemType == EItemType::Mount", EditConditionHides))
	int32 NaturalArmorProtection = 5;

	// Derived Statistics (Getters)
	int32 GetArmorProtection() const
	{
		return NaturalArmorProtection + HorseArmor.ArmorProtection;
	}
};

// Représente un emplacement d'équipement actif avec son contenu typé
USTRUCT(BlueprintType)
struct FEquippedItemSlot
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment")
	EEquipmentSlot Slot = EEquipmentSlot::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment")
	bool bIsOccupied = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment")
	EItemType EquippedItemType = EItemType::General;

	// Métadonnées de base
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment", meta = (EditCondition = "EquippedItemType == EItemType::General || EquippedItemType == EItemType::Clothing", EditConditionHides))
	FPendragonItem BaseItem;

	// Données spécifiques selon le type d'objet équipé
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment", meta = (EditCondition = "EquippedItemType == EItemType::Weapon", EditConditionHides))
	FWeapon EquippedWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment", meta = (EditCondition = "EquippedItemType == EItemType::Shield", EditConditionHides))
	FShield EquippedShield;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment", meta = (EditCondition = "EquippedItemType == EItemType::Armor", EditConditionHides))
	FArmor EquippedArmor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment", meta = (EditCondition = "EquippedItemType == EItemType::Mount", EditConditionHides))
	FHorse EquippedHorse;
};
