#pragma once

#include "CoreMinimal.h"
#include "MedievalKnightEnums.generated.h"

UENUM(BlueprintType)
enum class ETrait : uint8
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
enum class EDiceCheckResult : uint8
{
	CriticalSuccess UMETA(DisplayName = "Critical Success"),
	Success         UMETA(DisplayName = "Success"),
	Failure         UMETA(DisplayName = "Failure"),
	Fumble          UMETA(DisplayName = "Fumble")
};

UENUM(BlueprintType)
enum class EAttribute : uint8
{
	Size,
	Dexterity,
	Strength,
	Constitution,
	Appeal
};

// Types de Passions dans Pendragon
UENUM(BlueprintType)
enum class EPassionGroup : uint8
{
	None        UMETA(DisplayName = "None / Individual"),
	Fidelitas   UMETA(DisplayName = "Fidelitas"),
	Fervor      UMETA(DisplayName = "Fervor"),
	Adoratio    UMETA(DisplayName = "Adoratio"),
	Civilitas   UMETA(DisplayName = "Civilitas")
};

UENUM(BlueprintType)
enum class EPassionType : uint8
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
enum class ESkillCategory : uint8
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
	Dagger			UMETA(DisplayName = "Dagger"),
	Belt1			UMETA(DisplayName = "Belt1"),
	Belt2			UMETA(DisplayName = "Belt2"),
	JoustingWeapon	UMETA(DisplayName = "Jousting Weapon"),
	RangedWeapon	UMETA(DisplayName = "Ranged Weapon"),
	Clothing		UMETA(DisplayName = "Clothing"),
	Cape			UMETA(DisplayName = "Cape"),
	ArmorMailPlate	UMETA(DisplayName = "Mail/Plate"),
	ArmorTextile	UMETA(DisplayName = "Textile"),
	ArmorHelm		UMETA(DisplayName = "Helmet"),
	ArmorTabard 	UMETA(DisplayName = "Tabard"),
	WarMount		UMETA(DisplayName = "War Mount"),
	RidingMount		UMETA(DisplayName = "Riding Mount"),
	TransportMount	UMETA(DisplayName = "Transport Animal")
};

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	None		UMETA(DisplayName = "None"),
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
	None	UMETA(DisplayName = "None"),
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
enum class EHorseColor : uint8
{
	None		UMETA(DisplayName = "None"),
	White		UMETA(DisplayName = "White"),
	Gray		UMETA(DisplayName = "Gray"),
	Bay			UMETA(DisplayName = "Bay"),
	Yellow		UMETA(DisplayName = "Yellow"),
	Pale		UMETA(DisplayName = "Pale"),
	Chestnut	UMETA(DisplayName = "Chestnut"),
	Dun			UMETA(DisplayName = "Dun"),
	Black		UMETA(DisplayName = "Black")
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
enum class EAdvantageType : uint8
{
	None					UMETA(DisplayName = "None"),
	BreaksOtherTypesOnTie	UMETA(DisplayName = "Breaks other Types on Tie"),
	BreaksHaftedOnTie		UMETA(DisplayName = "Breaks Hafted on Tie"),
	DoesNotBreakOnFumble	UMETA(DisplayName = "Does not break on Fumble"),
	LongWeapon				UMETA(DisplayName = "Long Weapon"),
	Parry					UMETA(DisplayName = "Parry"),
	AgainstMail 			UMETA(DisplayName = "Against Mail"),
	AgainstPlate			UMETA(DisplayName = "Against Plate"),
	AgainstUnarmored		UMETA(DisplayName = "Against Unarmored"),
	IgnoresShieldParry		UMETA(DisplayName = "Ignores Shield and Parry AP"),
	ReduceShield			UMETA(DisplayName = "Reduce Shield"),
	WhenTwoHanded			UMETA(DisplayName = "When Two Handed")
};

UENUM(BlueprintType)
enum class EDisadvantageType : uint8
{
	None					UMETA(DisplayName = "None"),
	NoShield				UMETA(DisplayName = "No Shield"),
	BreaksOnFumble			UMETA(DisplayName = "Breaks on Fumble"),
	BreaksOnTie 			UMETA(DisplayName = "Breaks on Tie"),
	BreaksOnTieVsSword		UMETA(DisplayName = "Breaks on Tie vs Sword"),
	BreaksOnOddSuccess		UMETA(DisplayName = "Breaks on odd Success"),
	BreaksOnSuccess 		UMETA(DisplayName = "Breaks on Success")
};

UENUM(BlueprintType)
enum class ECombatTactic : uint8
{
	Normal,         // Jet standard
	AllOutAttack,   // Attaque féroce (+4 aux dégâts, mais -5 à la compétence de défense)
	Defensive,      // Posture défensive (+5 à la compétence, mais aucun dégât infligé)
	Prudent         // Esquive / Retraite contrôlée
};

UENUM(BlueprintType)
enum class EGender : uint8
{
	Male        UMETA(DisplayName = "Man"),
	Female      UMETA(DisplayName = "Woman")
};

/** Les 7 choix d'augmentation lors de la création de personnage */
UENUM(BlueprintType)
enum class ECreationBonusType : uint8
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
enum class ELocalCulture : uint8
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
	Valois		UMETA(DisplayName = "Valois"),
	Cornwall	UMETA(DisplayName = "Cornwall"),
	Irish		UMETA(DisplayName = "Irish"),
	Londres		UMETA(DisplayName = "London"),
	Mercia		UMETA(DisplayName = "Mercia"),
	Northern 	UMETA(DisplayName = "Northern"),
	Welsh		UMETA(DisplayName = "Welsh"),
	Wessex		UMETA(DisplayName = "Wessex")
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
enum class EReligion : uint8
{
	Christian		UMETA(DisplayName = "Christian"),
	Pagan 			UMETA(DisplayName = "Pagan")
};

UENUM(BlueprintType)
enum class ERelationType : uint8
{
	Father			UMETA(DisplayName = "Father"),
	Mother			UMETA(DisplayName = "Mother"),
	Sibling			UMETA(DisplayName = "Sibling"),
	Spouse			UMETA(DisplayName = "Spouse"),
	Child			UMETA(DisplayName = "Child"),
	Friend			UMETA(DisplayName = "Friend"),
	Mentor			UMETA(DisplayName = "Mentor"),
	Enemy			UMETA(DisplayName = "Enemy"),
	Liege			UMETA(DisplayName = "Liege"),
	Vassal			UMETA(DisplayName = "Vassal"),
	Squire			UMETA(DisplayName = "Squire"),
	Subordinate		UMETA(DisplayName = "Subordinate"),
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

UENUM(BlueprintType)
enum class EHairColor : uint8
{
	Blond			UMETA(DisplayName = "Blond"),
	DarkBlond		UMETA(DisplayName = "Dark Blond"),
	Brown			UMETA(DisplayName = "Brown"),
	DarkBrown		UMETA(DisplayName = "Dark Brown"),
	Black			UMETA(DisplayName = "Black"),
	Aubrun 			UMETA(DisplayName = "Aubrun"),
	Red				UMETA(DisplayName = "Red"),
	Gray			UMETA(DisplayName = "Gray"),
	White			UMETA(DisplayName = "White"),
};

UENUM(BlueprintType)
enum class EEyeColor : uint8
{
	Green			UMETA(DisplayName = "Green"),
	Amber			UMETA(DisplayName = "Amber"),
	Hazel			UMETA(DisplayName = "Hazel"),
	Blue			UMETA(DisplayName = "Blue"),
	LightBrown		UMETA(DisplayName = "Light Brown"),
	DarkBrown		UMETA(DisplayName = "Dark Brown"),
	Black			UMETA(DisplayName = "Black"),
	Heterochromia	UMETA(DisplayName = "Heterochromia"),
};

UENUM(BlueprintType)
enum class EDistinctiveFeatures : uint8
{
	// Physique Positive
	BarrelChested	UMETA(DisplayName = "Barrel-chested"),
	Brawny 			UMETA(DisplayName = "Brawny"),
	Buxom 			UMETA(DisplayName = "Buxom"),
	Curvy 			UMETA(DisplayName = "Curvy"),
	Muscular		UMETA(DisplayName = "Muscular"),
	Petite			UMETA(DisplayName = "Petite"),
	Solid			UMETA(DisplayName = "Solid"),
	Statuesque 		UMETA(DisplayName = "Statuesque"),

	// Physique Negative
	Flabby			UMETA(DisplayName = "Flabby"),
	Gangly			UMETA(DisplayName = "Gangly"),
	Gawky			UMETA(DisplayName = "Gawky"),
	Hunched			UMETA(DisplayName = "Hunched"),
	Lanky			UMETA(DisplayName = "Lanky"),
	Overweight		UMETA(DisplayName = "Overweight"),
	Skinny			UMETA(DisplayName = "Skinny"),
	Stooped			UMETA(DisplayName = "Stooped"),

	// Hair Positive
	Curly			UMETA(DisplayName = "Curly"),
	Flowing			UMETA(DisplayName = "Flowing"),
	Straight		UMETA(DisplayName = "Straight"),
	Wavy			UMETA(DisplayName = "Wavy"),

	// Hair Negative
	Bald 			UMETA(DisplayName = "Bald"),
	Patchy			UMETA(DisplayName = "Patchy"),
	PrematurelyGrey	UMETA(DisplayName = "Prematurely Grey"),
	Thinning		UMETA(DisplayName = "Thinning"),

	// Face Positive
	BroadNose 		UMETA(DisplayName = "Broad Nose"),
	ButtonNose 		UMETA(DisplayName = "Button Nose"),
	CleanShaven		UMETA(DisplayName = "Clean Shaven"),
	StraightTeeth 	UMETA(DisplayName = "Straight Teeth"),

	// Face Negative
	BigEars 		UMETA(DisplayName = "BigEars"),
	CrookedTeeth 	UMETA(DisplayName = "Crooked Teeth"),
	Pockmarks 		UMETA(DisplayName = "Pockmarks"),
	Scars 			UMETA(DisplayName = "Scars"),

	// Speech Positive
	Charming 		UMETA(DisplayName = "Charming"),
	Clear 			UMETA(DisplayName = "Clear"),
	Deep 			UMETA(DisplayName = "Deep"),
	Resonant		UMETA(DisplayName = "Resonant"),

	// Speech Negative
	Bellowing 		UMETA(DisplayName = "Bellowing"),
	Nasal			UMETA(DisplayName = "Nasal"),
	Lisp			UMETA(DisplayName = "Lisp"),
	Stutter 		UMETA(DisplayName = "Stutter"),
};
