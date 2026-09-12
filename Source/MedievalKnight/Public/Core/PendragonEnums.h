#pragma once

#include "CoreMinimal.h"
#include "PendragonEnums.generated.h"

UENUM(BlueprintType)
enum class EPendragonTrait : uint8
{
	Chaste			UMETA(DisplayName = "Chaste"),
	Lustful			UMETA(DisplayName = "Lubrique"),
	Energetic		UMETA(DisplayName = "Dynamique"),
	Lazy			UMETA(DisplayName = "Fainéant"),
	Forgiving		UMETA(DisplayName = "Indulgent"),
	Vengeful		UMETA(DisplayName = "Vengeur"),
	Generous 		UMETA(DisplayName = "Généreux"),
	Selfish			UMETA(DisplayName = "Égoïste"),
	Honest 			UMETA(DisplayName = "Honnête"),
	Deceitful		UMETA(DisplayName = "Fourbe"),
	Just 			UMETA(DisplayName = "Juste"),
	Arbitrary		UMETA(DisplayName = "Arbitraire"),
	Merciful		UMETA(DisplayName = "Clément"),
	Cruel			UMETA(DisplayName = "Cruel"),
	Modest 			UMETA(DisplayName = "Modeste"),
	Proud			UMETA(DisplayName = "Fier"),
	Prudent 		UMETA(DisplayName = "Prudent"),
	Reckless		UMETA(DisplayName = "Téméraire"),
	Spiritual		UMETA(DisplayName = "Spirituel"),
	Worldly			UMETA(DisplayName = "Mondain"),
	Temperate		UMETA(DisplayName = "Tempéré"),
	Indulgent		UMETA(DisplayName = "Laxiste"),
	Trusting		UMETA(DisplayName = "Confiant"),
	Suspicious		UMETA(DisplayName = "Méfiant"),
	Valorous		UMETA(DisplayName = "Valeureux"),
	Cowardly		UMETA(DisplayName = "Lâche")
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
	Appearance
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

UENUM(BlueprintType)
enum class EPendragonSkillCategory : uint8
{
	Combat      UMETA(DisplayName = "Combat"),
	Civilian    UMETA(DisplayName = "Civilian / Non-Combat")
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
	MainHand		UMETA(DisplayName = "Main dominante"),
	OffHand			UMETA(DisplayName = "Main non dominante"),
	BeltMain		UMETA(DisplayName = "Ceinture 1"),
	BeltSecondary	UMETA(DisplayName = "Ceinture 2"),
	JoustingWeapon	UMETA(DisplayName = "Arme de Joute"),
	RangedWeapon	UMETA(DisplayName = "Arme à distance"),
	Clothing		UMETA(DisplayName = "Vêtements"),
	ArmorMailPlate	UMETA(DisplayName = "Armure métallique"),
	ArmorTextile	UMETA(DisplayName = "Armure textile"),
	ArmorHelm		UMETA(DisplayName = "Casque"),
	ArmorSurcoat	UMETA(DisplayName = "Surcot"),
	ArmorTabard 	UMETA(DisplayName = "Tabard"),
	WarMount		UMETA(DisplayName = "Monture de guerre"),
	RidingMount		UMETA(DisplayName = "Monture de voyage"),
	TransportMount	UMETA(DisplayName = "Animal de transport")
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
	Attribute   UMETA(DisplayName = "+1 Attribut (Taille, Dextérité, Force, Constitution, Apparence)"),
	Trait       UMETA(DisplayName = "+1 Trait ou Passion"),
	Skills      UMETA(DisplayName = "+6 Points de Compétences")
};

