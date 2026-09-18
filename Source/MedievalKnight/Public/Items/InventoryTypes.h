#pragma once

#include "CoreMinimal.h"
#include "Core/PendragonTypes.h"
#include "InventoryTypes.generated.h"

USTRUCT(BlueprintType)
struct FPendragonItem : public FTableRowBase
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

	// Texture2D'/Game/Assets/Textures/items/FOLDER/TEXTURE.TEXTURE'
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName IconTexturePath;

	// Valeur financière en Deniers / Sous
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Economy")
	int32 ValueInDenarii = 0;

	// Quantité
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 Quantity = 1;
};

USTRUCT(BlueprintType)
struct FWeapon : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ItemID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FText ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EItemType ItemType = EItemType::Weapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EEquipmentSlot Slot = EEquipmentSlot::MainHand;

	// Texture2D'/Game/Assets/Textures/items/FOLDER/TEXTURE.TEXTURE'
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName IconTexturePath;

	// Valeur financière en Deniers / Sous
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Economy")
	int32 ValueInDenarii = 0;

	// Quantité
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 Quantity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon")
	EWeaponType WeaponType = EWeaponType::Sword;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon")
	EWeaponType WeaponAltType = EWeaponType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon")
	EWeaponSubType WeaponSubType = EWeaponSubType::ArmingSword;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon)")
	EFootMountedType FootMountedType = EFootMountedType::Foot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon)")
	ERange Range = ERange::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon")
	bool TwoHanded = false;

	// Statistiques d'équipement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon")
	int32 BonusDamage = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon")
	int32 FlatDamage = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon")
	int32 BonusThrown = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon")
	int32 FlatThrown = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon")
	int32 DamageDiceMax = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon")
	int32 DiceBonusTwoHanded = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon")
	int32 ReloadTime = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon")
	TMap<EAdvantageType, int32> Advantages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Weapon")
	TArray<EDisadvantageType> Disadvantages;
};

USTRUCT(BlueprintType)
struct FArmor : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ItemID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FText ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EItemType ItemType = EItemType::Armor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EEquipmentSlot Slot = EEquipmentSlot::ArmorMailPlate;

	// Texture2D'/Game/Assets/Textures/items/FOLDER/TEXTURE.TEXTURE'
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName IconTexturePath;

	// Valeur financière en Deniers / Sous
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Economy")
	int32 ValueInDenarii = 0;

	// Quantité
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 Quantity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Armor")
	EArmorType ArmorType = EArmorType::Textile;

	// Statistiques d'équipement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Stats")
	int32 ArmorProtection = 0;
};

USTRUCT(BlueprintType)
struct FShield : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ItemID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FText ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EItemType ItemType = EItemType::Shield;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EEquipmentSlot Slot = EEquipmentSlot::OffHand;

	// Texture2D'/Game/Assets/Textures/items/FOLDER/TEXTURE.TEXTURE'
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName IconTexturePath;

	// Valeur financière en Deniers / Sous
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Economy")
	int32 ValueInDenarii = 0;

	// Quantité
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 Quantity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Shield")
	EShieldType ShieldType = EShieldType::Medium;

	// Statistiques d'équipement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Stats")
	int32 ArmorProtection = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Stats")
	int32 MissileAttackPenalty = 0;
};

USTRUCT(BlueprintType)
struct FHorseArmor : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ItemID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FText ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EItemType ItemType = EItemType::HorseArmor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EEquipmentSlot Slot = EEquipmentSlot::WarMount;

	// Texture2D'/Game/Assets/Textures/items/FOLDER/TEXTURE.TEXTURE'
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName IconTexturePath;

	// Valeur financière en Deniers / Sous
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Economy")
	int32 ValueInDenarii = 0;

	// Quantité
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 Quantity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|HorseArmor")
	EHorseArmorType HorseArmorType = EHorseArmorType::CaparisonOpen;

	// Statistiques d'équipement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Stats")
	int32 ArmorProtection = 0;
};

USTRUCT(BlueprintType)
struct FHorse : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ItemID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FText ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EItemType ItemType = EItemType::Mount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EHorseColor HorseColor = EHorseColor::Dun;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EEquipmentSlot Slot = EEquipmentSlot::WarMount;

	// Texture2D'/Game/Assets/Textures/items/FOLDER/TEXTURE.TEXTURE'
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName IconTexturePath;

	// Valeur financière en Deniers / Sous
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Economy")
	int32 ValueInDenarii = 0;

	// Quantité
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 Quantity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	EHorseType HorseType = EHorseType::Combat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	EHorseSubType HorseSubType = EHorseSubType::Charger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	int32 NormalDamage = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	int32 ChargeDamage = 6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	int32 Move = 16;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Stats")
	int32 NaturalArmorProtection = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	int32 Size = 40;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	int32 Dexterity = 13;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	int32 Strength = 32;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	int32 Constitution = 15;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	int32 HP = 55;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	FHorseArmor Caparison;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	FHorseArmor HorseArmor;

	// Statistiques d'équipement

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
