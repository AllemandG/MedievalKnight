#pragma once

#include "CoreMinimal.h"
#include "Core/PendragonTypes.h"
#include "InventoryTypes.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Weapon      UMETA(DisplayName = "Weapon"),
	Shield      UMETA(DisplayName = "Shield"),
	Armor       UMETA(DisplayName = "Armor"),
	Mount       UMETA(DisplayName = "Mount/Horse"),
	HorseArmor  UMETA(DisplayName = "HorseArmor"),
	Clothing    UMETA(DisplayName = "Clothing"),
	General     UMETA(DisplayName = "General Item")
};

UENUM(BlueprintType)
enum class EEquipmentSlot : uint8
{
	None			UMETA(DisplayName = "None"),
	MainHand		UMETA(DisplayName = "Main Hand"),
	OffHand			UMETA(DisplayName = "Off Hand"),
	BeltMain		UMETA(DisplayName = "Belt Main"),
	BeltSecondary	UMETA(DisplayName = "Belt Secondary"),
	RangedWeapon	UMETA(DisplayName = "Ranged Weapon"),
	Clothing		UMETA(DisplayName = "Clothing"),
	Armor			UMETA(DisplayName = "Armor"),
	ArmorMailPlate	UMETA(DisplayName = "Armor Mail/Plate"),
	ArmorTextile	UMETA(DisplayName = "Armor Textile"),
	ArmorHelm		UMETA(DisplayName = "Armor Helm"),
	ArmorSurcoat	UMETA(DisplayName = "Armor Surcoat"),
	ArmorTabard 	UMETA(DisplayName = "Armor Tabard"),
	WarMount		UMETA(DisplayName = "War Mount"),
	RidingMount		UMETA(DisplayName = "Riding Mount"),
	TransportMount	UMETA(DisplayName = "Transport Mount")
};

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Charge      UMETA(DisplayName = "Charge"),
	Sword		UMETA(DisplayName = "Sword"),
	Spear       UMETA(DisplayName = "Spear"),
	Hafted      UMETA(DisplayName = "Hafted"),
	TwoHafted   UMETA(DisplayName = "Two-Handed Hafted"),
	Brawling	UMETA(DisplayName = "Brawling"),
	Improvised  UMETA(DisplayName = "Improvised"),
	Bow			UMETA(DisplayName = "Bow"),
	Crossbow    UMETA(DisplayName = "Crossbow"),
	Thrown		UMETA(DisplayName = "Thrown")
};

UENUM(BlueprintType)
enum class EWeaponSubType : uint8
{
	Lance			UMETA(DisplayName = "Lance"),
	JoustingLance	UMETA(DisplayName = "Jousting Lance"),
	LanceFrangible	UMETA(DisplayName = "Lance, Frangible"),
	ArmingSword		UMETA(DisplayName = "Arming Sword"),
	Longsword		UMETA(DisplayName = "Longsword"),
	Falchion		UMETA(DisplayName = "Falchion"),
	TwoFalchin 		UMETA(DisplayName = "Falchin, 2H"),
	Javelin			UMETA(DisplayName = "Javelin"),
	Spear 			UMETA(DisplayName = "Spear"),
	BattleAxe		UMETA(DisplayName = "Battle Axe"),
	Cudgel 			UMETA(DisplayName = "Cudgel"),
	Francisca 		UMETA(DisplayName = "Francisca"),
	Mace			UMETA(DisplayName = "Mace"),
	Quarterstaff	UMETA(DisplayName = "Quarterstaff"),
	Hammer			UMETA(DisplayName = "Hammer"),
	Club			UMETA(DisplayName = "Club"),
	GreatAxe		UMETA(DisplayName = "Great Axe"),
	GreatMace		UMETA(DisplayName = "Great Mace"),
	Maul 			UMETA(DisplayName = "Maul"),
	Bill			UMETA(DisplayName = "Bill"),
	Glaive			UMETA(DisplayName = "Glaive"),
	Halberd			UMETA(DisplayName = "Halberd"),
	TwoLance		UMETA(DisplayName = "Lance, 2H"),
	Pollaxe			UMETA(DisplayName = "Pollaxe"),
	WarHammer		UMETA(DisplayName = "War Hammer"),
	Dagger			UMETA(DisplayName = "Dagger"),
	Seax 			UMETA(DisplayName = "Seax"),
	Improvised		UMETA(DisplayName = "Improvised"),
	SelfBow			UMETA(DisplayName = "Self Bow"),
	Longbow			UMETA(DisplayName = "Longbow"),
	Warbow			UMETA(DisplayName = "Warbow"),
	CrossbowLight	UMETA(DisplayName = "Crossbow, Light"),
	CrossbowMedium	UMETA(DisplayName = "Crossbow, Medium"),
	CrossbowHeavy	UMETA(DisplayName = "Crossbow, Heavy")
};

UENUM(BlueprintType)
enum class EFootMountedType : uint8
{
	Foot		UMETA(DisplayName = "Foot"),
	Mounted		UMETA(DisplayName = "Mounted"),
	Both		UMETA(DisplayName = "Both")
};

UENUM(BlueprintType)
enum class ERange : uint8
{
	Short	UMETA(DisplayName = "Short"),
	Medium	UMETA(DisplayName = "Medium"),
	Long	UMETA(DisplayName = "Long")
};

UENUM(BlueprintType)
enum class EArmorType : uint8
{
	Textile		UMETA(DisplayName = "Textile"),
	Mail		UMETA(DisplayName = "Mail"),
	Plate       UMETA(DisplayName = "Plate"),
	Helm		UMETA(DisplayName = "Helm"),
	Surcoat     UMETA(DisplayName = "Surcoat"),
	Tabard      UMETA(DisplayName = "Tabard")
};

UENUM()
enum class EShieldType : uint8
{
	Small	UMETA(DisplayName = "Small"),
	Medium	UMETA(DisplayName = "Medium"),
	Large	UMETA(DisplayName = "Large")
};

UENUM(BlueprintType)
enum class EHorseType : uint8
{
	Combat	UMETA(DisplayName = "Combat"),
	Riding	UMETA(DisplayName = "Riding"),
	Work	UMETA(DisplayName = "Work")
};

UENUM(BlueprintType)
enum class EHorseSubType : uint8
{
	Hobby			UMETA(DisplayName = "Hobby"),
	Charger			UMETA(DisplayName = "Charger"),
	ChargerSmall	UMETA(DisplayName = "Charger, small"),
	ChargerLarge 	UMETA(DisplayName = "Charger, large"),
	Destrier 		UMETA(DisplayName = "Destrier"),
	GreatHorse		UMETA(DisplayName = "Great Horse"),
	Jennet			UMETA(DisplayName = "Jennet"),
	Rouncy			UMETA(DisplayName = "Rouncy"),
	RouncySmall		UMETA(DisplayName = "Rouncy, small"),
	RouncyInferior	UMETA(DisplayName = "Rouncy, inferior"),
	RouncyLarge		UMETA(DisplayName = "Rouncy, large"),
	Courser			UMETA(DisplayName = "Courser"),
	CartHorse		UMETA(DisplayName = "Cart Horse"),
	Cob				UMETA(DisplayName = "Cob"),
	Nag				UMETA(DisplayName = "Nag"),
	Sumpter			UMETA(DisplayName = "Sumpter"),
	SumpterStrong	UMETA(DisplayName = "Sumpter, strong"),
	Hackney			UMETA(DisplayName = "Hackney"),
	Donkey			UMETA(DisplayName = "Donkey"),
	Mule			UMETA(DisplayName = "Mule"),
};

UENUM(BlueprintType)
enum class EHorseArmorType : uint8
{
	CaparisonOpen	UMETA(DisplayName = "Caparison, open"),
	CaparisonHalf	UMETA(DisplayName = "Caparison, half"),
	CaparisonFull	UMETA(DisplayName = "Caparison, full"),
	PaddingFull		UMETA(DisplayName = "Padding, full"),
	GambesonHalf	UMETA(DisplayName = "Gambeson, half"),
	GambesonFull	UMETA(DisplayName = "Gambeson, full")
};

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
	FPendragonAttributes Attributes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	FHorseArmor Caparison;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Horse")
	FHorseArmor HorseArmor;

	// Statistiques d'équipement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Stats", meta = (EditCondition = "ItemType == EItemType::Mount", EditConditionHides))
	int32 NaturalArmorProtection = 0;

	// Derived Statistics (Getters)
	int32 GetArmorProtection() const
	{
		return NaturalArmorProtection + HorseArmor.ArmorProtection;
	}
};
