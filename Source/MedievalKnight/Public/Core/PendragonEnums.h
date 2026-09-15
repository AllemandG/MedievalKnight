#pragma once

#include "CoreMinimal.h"
#include "PendragonEnums.generated.h"

UENUM(BlueprintType)
enum class EPendragonTrait : uint8
{
	Chaste			UMETA(DisplayName = "Chaste"),
	Lustful			UMETA(DisplayName = "Lustful"),
	Energetic		UMETA(DisplayName = "Energetic"),
	Lazy			UMETA(DisplayName = "Lazy"),
	Forgiving		UMETA(DisplayName = "Forgiving"),
	Vengeful		UMETA(DisplayName = "Vengeful"),
	Generous 		UMETA(DisplayName = "Generous"),
	Selfish			UMETA(DisplayName = "Selfish"),
	Honest 			UMETA(DisplayName = "Honest"),
	Deceitful		UMETA(DisplayName = "Deceitful"),
	Just 			UMETA(DisplayName = "Just"),
	Arbitrary		UMETA(DisplayName = "Arbitrary"),
	Merciful		UMETA(DisplayName = "Merciful"),
	Cruel			UMETA(DisplayName = "Cruel"),
	Modest 			UMETA(DisplayName = "Modest"),
	Proud			UMETA(DisplayName = "Proud"),
	Prudent 		UMETA(DisplayName = "Prudent"),
	Reckless		UMETA(DisplayName = "Reckless"),
	Spiritual		UMETA(DisplayName = "Spiritual"),
	Worldly			UMETA(DisplayName = "Worldly"),
	Temperate		UMETA(DisplayName = "Temperate"),
	Indulgent		UMETA(DisplayName = "Indulgent"),
	Trusting		UMETA(DisplayName = "Trusting"),
	Suspicious		UMETA(DisplayName = "Suspicious"),
	Valorous		UMETA(DisplayName = "Valorous"),
	Cowardly		UMETA(DisplayName = "Cowardly")
};

UENUM(BlueprintType)
enum class EPendragonCheckResult : uint8
{
	CriticalSuccess UMETA(DisplayName = "Critical Success"),
	Success         UMETA(DisplayName = "Success"),
	Failure         UMETA(DisplayName = "Failure"),
	Fumble          UMETA(DisplayName = "Fumble")
};

UENUM(BlueprintType)
enum class EPendragonAttribute : uint8
{
	Size,
	Dexterity,
	Strength,
	Constitution,
	Appeal
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

	// Obsessions
	Avarice     UMETA(DisplayName = "Avarice"),
	Fear        UMETA(DisplayName = "Fear"),
	Jealousy	UMETA(DisplayName = "Jealousy"),

	// Afflictions
	Madness		UMETA(DisplayName = "Madness"),
	Melancholy	UMETA(DisplayName = "Melancholy"),
	Misery		UMETA(DisplayName = "Misery")
};

UENUM(BlueprintType)
enum class EPendragonSkillCategory : uint8
{
	Combat      UMETA(DisplayName = "Combat"),
	Civilian    UMETA(DisplayName = "Civilian"),
};

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
	Belt			UMETA(DisplayName = "Belt"),
	JoustingWeapon	UMETA(DisplayName = "Jousting Weapon"),
	RangedWeapon	UMETA(DisplayName = "Ranged Weapon"),
	Clothing		UMETA(DisplayName = "Clothing"),
	Cape			UMETA(DisplayName = "Cape"),
	ArmorMailPlate	UMETA(DisplayName = "Mail/Plate"),
	ArmorTextile	UMETA(DisplayName = "Textile"),
	ArmorHelm		UMETA(DisplayName = "Helmet"),
	ArmorSurcoat	UMETA(DisplayName = "Surcoat"),
	ArmorTabard 	UMETA(DisplayName = "Tabard"),
	WarMount		UMETA(DisplayName = "War Mount"),
	RidingMount		UMETA(DisplayName = "Riding Mount"),
	TransportMount	UMETA(DisplayName = "Transport Animal")
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

UENUM(BlueprintType)
enum class EPendragonCombatTactic : uint8
{
	Normal,         // Jet standard
	AllOutAttack,   // Attaque féroce (+4 aux dégâts, mais -5 à la compétence de défense)
	Defensive,      // Posture défensive (+5 à la compétence, mais aucun dégât infligé)
	Prudent         // Esquive / Retraite contrôlée
};

UENUM(BlueprintType)
enum class EPendragonGender : uint8
{
	Male        UMETA(DisplayName = "Homme"),
	Female      UMETA(DisplayName = "Femme")
};

/** Les 7 choix d'augmentation lors de la création de personnage */
UENUM(BlueprintType)
enum class EPendragonBonusType : uint8
{
	Attribute   UMETA(DisplayName = "+1 Attribut"),
	Trait       UMETA(DisplayName = "+1 Trait or Passion"),
	Skills      UMETA(DisplayName = "+6 Skill Points")
};

UENUM(BlueprintType)
enum class ECulture : uint8
{
	French		UMETA(DisplayName = "French"),
	English		UMETA(DisplayName = "English")
};

UENUM(BlueprintType)
enum class ELocalFrenchCulture : uint8
{
	Aquitaine	UMETA(DisplayName = "Aquitaine"),
	Auvergne	UMETA(DisplayName = "Auvergne"),
	Bourgogne	UMETA(DisplayName = "Bourgogne"),
	Bretagne	UMETA(DisplayName = "Bretagne"),
	Champagne	UMETA(DisplayName = "Champagne"),
	Flandres	UMETA(DisplayName = "Flandres"),
	Gascogne	UMETA(DisplayName = "Gascogne"),
	Normandie	UMETA(DisplayName = "Normandie"),
	Occitanie	UMETA(DisplayName = "Occitanie"),
	Poitou 		UMETA(DisplayName = "Poitou"),
	Valois		UMETA(DisplayName = "Valois")
};

UENUM(BlueprintType)
enum class ELocalEnglishCulture : uint8
{
	Cornwall	UMETA(DisplayName = "Cornwall"),
	Irish		UMETA(DisplayName = "Irish"),
	Londres		UMETA(DisplayName = "London"),
	Mercia		UMETA(DisplayName = "Mercia"),
	Northern 	UMETA(DisplayName = "Northern"),
	Welsh		UMETA(DisplayName = "Welsh"),
	Wessex		UMETA(DisplayName = "Wessex"),
};

UENUM(BlueprintType)
enum class EFamilyCharacteristic : uint8
{
	Perceptive		UMETA(DisplayName = "Perceptive"),
	Martial			UMETA(DisplayName = "Martial"),
	Poetic			UMETA(DisplayName = "Poetic"),
	WellBred		UMETA(DisplayName = "Well-Bred"),
	Sprightly		UMETA(DisplayName = "Sprightly"),
	Seductive		UMETA(DisplayName = "Seductive"),
	BirdLover		UMETA(DisplayName = "Bird Lover"),
	Healer			UMETA(DisplayName = "Healer"),
	Astute			UMETA(DisplayName = "Astute"),
	Clever			UMETA(DisplayName = "Clever"),
	Equestrian		UMETA(DisplayName = "Equestrian"),
	Scheming 		UMETA(DisplayName = "Scheming"),
	SilverTongued	UMETA(DisplayName = "SilverTongued"),
	Literate 		UMETA(DisplayName = "Literate"),
	Everyman 		UMETA(DisplayName = "Everyman"),
	Musical			UMETA(DisplayName = "Musical"),
	Devout 			UMETA(DisplayName = "Devout"),
	Melodic			UMETA(DisplayName = "Melodic"),
	Clodhopper		UMETA(DisplayName = "Clodhopper"),
	Gifted			UMETA(DisplayName = "Gifted"),
};

UENUM(BlueprintType)
enum class ESkills : uint8
{
	Awareness		UMETA(DisplayName = "Awareness"),
	Battle			UMETA(DisplayName = "Battle"),
	Brawling 		UMETA(DisplayName = "Brawling"),
	Bow 			UMETA(DisplayName = "Bow"),
	Charge			UMETA(DisplayName = "Charge"),
	Chirurgery		UMETA(DisplayName = "Chirurgery"),
	Compose			UMETA(DisplayName = "Compose"),
	Courtesy		UMETA(DisplayName = "Courtesy"),
	Crossbow		UMETA(DisplayName = "Crossbow"),
	Dancing			UMETA(DisplayName = "Dancing"),
	Falconry		UMETA(DisplayName = "Falconry"),
	Fashion			UMETA(DisplayName = "Fashion"),
	FirstAid		UMETA(DisplayName = "First Aid"),
	Flirting		UMETA(DisplayName = "Flirting"),
	Folklore		UMETA(DisplayName = "Folklore"),
	Gaming			UMETA(DisplayName = "Gaming"),
	Hafted			UMETA(DisplayName = "Hafted"),
	Horsemanship	UMETA(DisplayName = "Horsemanship"),
	Hunting			UMETA(DisplayName = "Hunting"),
	Industry		UMETA(DisplayName = "Industry"),
	Intrigue		UMETA(DisplayName = "Intrigue"),
	Literacy		UMETA(DisplayName = "Literacy"),
	Orate			UMETA(DisplayName = "Orate"),
	PlayInstrument	UMETA(DisplayName = "Play Instrument"),
	Recognize		UMETA(DisplayName = "Recognize"),
	Religion		UMETA(DisplayName = "Religion"),
	Singing			UMETA(DisplayName = "Singing"),
	Spear 			UMETA(DisplayName = "Spear"),
	Stewardship		UMETA(DisplayName = "Stewardship"),
	Sword			UMETA(DisplayName = "Sword"),
	ThrownWeapon	UMETA(DisplayName = "Thrown Weapon"),
	TwoHafted		UMETA(DisplayName = "Two-Handed Hafted")
};

