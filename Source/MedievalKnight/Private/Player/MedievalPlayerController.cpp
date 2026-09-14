#include "MedievalKnight/Public/Player/MedievalPlayerController.h"

#include "Components/PendragonInventoryComponent.h"
#include "MedievalKnight/Public/Components/PendragonCharacterComponent.h"

AMedievalPlayerController::AMedievalPlayerController()
{
	// Instanciation automatique du composant sur le Controller
	CharacterComponent = CreateDefaultSubobject<UPendragonCharacterComponent>(TEXT("PendragonCharacterComponent"));
	InventoryComponent = CreateDefaultSubobject<UPendragonInventoryComponent>(TEXT("PendragonInventoryComponent"));
}

void AMedievalPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (InventoryComponent)
    {
        // 1. Une épée d'armement
	    FWeapon ArmingSword;
	    ArmingSword.ItemID = TEXT("ArmingSword_01");
	    ArmingSword.ItemName = FText::FromString(TEXT("Arming Sword"));
	    ArmingSword.Description = FText::FromString(TEXT("A balanced, tempered steel one-handed sword."));
	    ArmingSword.ItemType = EItemType::Weapon;
	    ArmingSword.WeaponType = EWeaponType::Sword;
	    ArmingSword.WeaponSubType = EWeaponSubType::ArmingSword;
	    ArmingSword.Slot = EEquipmentSlot::MainHand;
	    ArmingSword.FootMountedType = EFootMountedType::Both;
	    ArmingSword.BonusDamage = 0;
	    ArmingSword.ValueInDenarii = 120;

	    // 2. Un haubert de maille
	    FArmor Chainmail;
	    Chainmail.ItemID = TEXT("Chainmail_01");
	    Chainmail.ItemName = FText::FromString(TEXT("Hauberk"));
	    Chainmail.Description = FText::FromString(TEXT("Robust protection made of riveted steel mesh."));
	    Chainmail.ItemType = EItemType::Armor;
	    Chainmail.ArmorType = EArmorType::Mail;
	    Chainmail.Slot = EEquipmentSlot::ArmorMailPlate;
	    Chainmail.ArmorProtection = 6;
	    Chainmail.ValueInDenarii = 390;

	    // 3. Un destrier
	    FHorse Charger;
	    Charger.ItemID = TEXT("Charger_01");
	    Charger.ItemName = FText::FromString(TEXT("Bucephale"));
	    Charger.Description = FText::FromString(TEXT("A powerful warhorse trained for the charge."));
	    Charger.ItemType = EItemType::Mount;
	    Charger.HorseType = EHorseType::Combat;
	    Charger.HorseSubType = EHorseSubType::Charger;
	    Charger.ValueInDenarii = 1920;

	    // 4. Un Aketon
	    FArmor Aketon;
	    Aketon.ItemID = TEXT("Aketon_01");
	    Aketon.ItemName = FText::FromString(TEXT("Aketon"));
	    Aketon.Description = FText::FromString(TEXT("Padded textile protection worn under mail or plate armor."));
	    Aketon.ItemType = EItemType::Armor;
	    Aketon.ArmorType = EArmorType::Textile;
	    Aketon.Slot = EEquipmentSlot::ArmorTextile;
	    Aketon.ArmorProtection = 2;
	    Aketon.ValueInDenarii = 15;

	    // 5. Un Nasal Helm
	    FArmor NasalHelm;
	    NasalHelm.ItemID = TEXT("NasalHelm_01");
	    NasalHelm.ItemName = FText::FromString(TEXT("Nasal Helm"));
	    NasalHelm.Description = FText::FromString(TEXT("A steel helmet with a nasal guard."));
	    NasalHelm.ItemType = EItemType::Armor;
	    NasalHelm.ArmorType = EArmorType::Helm;
	    NasalHelm.Slot = EEquipmentSlot::ArmorHelm;
	    NasalHelm.ArmorProtection = 2;
	    NasalHelm.ValueInDenarii = 90;

	    // 6. Un Bouclier
	    FShield KiteShield;
	    KiteShield.ItemID = TEXT("KiteShield_01");
	    KiteShield.ItemName = FText::FromString(TEXT("Kite Shield"));
	    KiteShield.Description = FText::FromString(TEXT("A large, tapered wooden shield covered in leather or metal rims. It offers high passive defense but imposes a -2 Weapon Skill penalty to horseback attacks unless performing a couched lance charge."));
	    KiteShield.ItemType = EItemType::Shield;
	    KiteShield.ShieldType = EShieldType::Large;
	    KiteShield.Slot = EEquipmentSlot::OffHand;
	    KiteShield.ArmorProtection = 6;
	    KiteShield.ValueInDenarii = 30;

    	// 7. Une Arbalète légère
    	FWeapon CrossbowLight;
    	CrossbowLight.ItemID = TEXT("CrossbowLight_01");
    	CrossbowLight.ItemName = FText::FromString(TEXT("Light Crossbow"));
    	CrossbowLight.Description = FText::FromString(TEXT("A light crossbow; requires the user to be on foot to reload."));
    	CrossbowLight.ItemType = EItemType::Weapon;
    	CrossbowLight.WeaponType = EWeaponType::Crossbow;
    	CrossbowLight.WeaponSubType = EWeaponSubType::CrossbowLight;
    	CrossbowLight.Slot = EEquipmentSlot::RangedWeapon;
    	CrossbowLight.FootMountedType = EFootMountedType::Both;
    	CrossbowLight.BonusDamage = 1;
    	CrossbowLight.FlatDamage = 10;
    	CrossbowLight.ValueInDenarii = 60;

    	// Autres
    	FWeapon Dagger;
    	Dagger.ItemID = TEXT("Dagger_01");
    	Dagger.ItemName = FText::FromString(TEXT("Dagger"));
    	Dagger.Description = FText::FromString(TEXT("A tempered steel dagger."));
    	Dagger.ItemType = EItemType::Weapon;
    	Dagger.WeaponType = EWeaponType::Brawling;
    	Dagger.WeaponAltType = EWeaponType::Thrown;
    	Dagger.WeaponSubType = EWeaponSubType::Dagger;
    	Dagger.Slot = EEquipmentSlot::Belt;
    	Dagger.FootMountedType = EFootMountedType::Both;
    	Dagger.BonusDamage = 2;
    	Dagger.ValueInDenarii = 20;

    	FWeapon Lance;
    	Lance.ItemID = TEXT("Lance_01");
    	Lance.ItemName = FText::FromString(TEXT("Lance"));
    	Lance.Description = FText::FromString(TEXT("A long wooden spear weapon designed specifically for high-impact mounted charges."));
    	Lance.ItemType = EItemType::Weapon;
    	Lance.WeaponType = EWeaponType::Charge;
    	Lance.WeaponSubType = EWeaponSubType::Lance;
    	Lance.Slot = EEquipmentSlot::MainHand;
    	Lance.FootMountedType = EFootMountedType::Mounted;
    	Lance.BonusDamage = 0;
    	Lance.ValueInDenarii = 30;

    	FWeapon JoustingLance;
    	JoustingLance.ItemID = TEXT("JoustingLance_01");
    	JoustingLance.ItemName = FText::FromString(TEXT("Jousting Lance"));
    	JoustingLance.Description = FText::FromString(TEXT("A jousting lance designed to shatter more easily upon impact."));
    	JoustingLance.ItemType = EItemType::Weapon;
    	JoustingLance.WeaponType = EWeaponType::Charge;
    	JoustingLance.WeaponSubType = EWeaponSubType::JoustingLance;
    	JoustingLance.Slot = EEquipmentSlot::MainHand;
    	JoustingLance.FootMountedType = EFootMountedType::Mounted;
    	JoustingLance.BonusDamage = 0;
    	JoustingLance.ValueInDenarii = 3;

    	// General Items
		FPendragonItem OrdinaryClothing;
	    OrdinaryClothing.ItemID = TEXT("OrdinaryClothing_01");
	    OrdinaryClothing.ItemName = FText::FromString(TEXT("Ordinary Clothes"));
	    OrdinaryClothing.Description = FText::FromString(TEXT("A set of ordinary clothes."));
	    OrdinaryClothing.ItemType = EItemType::Clothing;
	    OrdinaryClothing.ValueInDenarii = 30;

	    FPendragonItem FineClothing;
	    FineClothing.ItemID = TEXT("FineClothing_01");
	    FineClothing.ItemName = FText::FromString(TEXT("Fine Clothes"));
	    FineClothing.Description = FText::FromString(TEXT("A set of clothes worth £1."));
	    FineClothing.ItemType = EItemType::Clothing;
    	FineClothing.ValueInDenarii = 240;
    	
    	FPendragonItem NobleClothing;
    	NobleClothing.ItemID = TEXT("NobleClothing_01");
    	NobleClothing.ItemName = FText::FromString(TEXT("Noble attire"));
    	NobleClothing.Description = FText::FromString(TEXT("A set of fine clothing worth £3."));
    	NobleClothing.ItemType = EItemType::Clothing;
    	NobleClothing.ValueInDenarii = 720;

	    FPendragonItem Cloak;
	    Cloak.ItemID = TEXT("Cloak_01");
	    Cloak.ItemName = FText::FromString(TEXT("Cloak"));
	    Cloak.Description = FText::FromString(TEXT("A cape to protect against the elements."));
	    Cloak.ItemType = EItemType::Clothing;
	    Cloak.ValueInDenarii = 5;

	    FPendragonItem WoolCloak;
	    WoolCloak.ItemID = TEXT("WoolCloak_01");
	    WoolCloak.ItemName = FText::FromString(TEXT("Wool Cloak"));
	    WoolCloak.Description = FText::FromString(TEXT("A wool cape to protect against the cold."));
	    WoolCloak.ItemType = EItemType::Clothing;
	    WoolCloak.ValueInDenarii = 10;

	    FPendragonItem TravelGear;
	    TravelGear.ItemID = TEXT("TravelGear_01");
	    TravelGear.ItemName = FText::FromString(TEXT("Travel Gear"));
	    TravelGear.Description = FText::FromString(TEXT("Two sleeping blankets and towels; eating and cooking utensils; fire-making kit; bandages; pair of panniers; several sacks with drawstrings to store everything; large canvas tarpaulin; pack frame for sumpter and saddlebags"));
	    TravelGear.ItemType = EItemType::General;
	    TravelGear.ValueInDenarii = 120;

	    FPendragonItem HorseGear;
	    HorseGear.ItemID = TEXT("HorseGear_01");
	    HorseGear.ItemName = FText::FromString(TEXT("Horse Gear"));
	    HorseGear.Description = FText::FromString(TEXT("Two ridding saddles and tack; One War saddle and tack; Four horse blankets; Feed bag; Currying brushes; Hobbles; Hoof pick; Horse towels; Rope"));
	    HorseGear.ItemType = EItemType::General;
	    HorseGear.ValueInDenarii = 120;
    	

        // Ajout à l'inventaire puis équipement direct
        InventoryComponent->AddWeapon(ArmingSword);
        InventoryComponent->AddArmor(Chainmail);
        InventoryComponent->AddMount(Charger);
    	InventoryComponent->AddArmor(Aketon);
    	InventoryComponent->AddArmor(NasalHelm);
    	InventoryComponent->AddShield(KiteShield);
    	InventoryComponent->AddWeapon(CrossbowLight);
    	InventoryComponent->AddWeapon(Dagger);
    	InventoryComponent->AddWeapon(Lance);
    	InventoryComponent->AddWeapon(JoustingLance);
    	InventoryComponent->AddWeapon(JoustingLance);
    	InventoryComponent->AddWeapon(JoustingLance);
    	InventoryComponent->AddWeapon(JoustingLance);
    	InventoryComponent->AddItem(OrdinaryClothing);
    	InventoryComponent->AddItem(FineClothing);
    	InventoryComponent->AddItem(NobleClothing);
    	InventoryComponent->AddItem(Cloak);
    	InventoryComponent->AddItem(WoolCloak);
    	InventoryComponent->AddItem(TravelGear);
    	InventoryComponent->AddItem(HorseGear);

        InventoryComponent->EquipWeapon(ArmingSword, EEquipmentSlot::MainHand);
        InventoryComponent->EquipMount(Charger, EEquipmentSlot::WarMount);
        InventoryComponent->EquipArmor(Aketon);
    	InventoryComponent->EquipArmor(Chainmail);
    	InventoryComponent->EquipArmor(NasalHelm);
    	InventoryComponent->EquipShield(KiteShield);
    	InventoryComponent->EquipWeapon(CrossbowLight, EEquipmentSlot::RangedWeapon);
    	InventoryComponent->EquipWeapon(Dagger, EEquipmentSlot::Belt);
    	InventoryComponent->EquipWeapon(Lance, EEquipmentSlot::JoustingWeapon);
		InventoryComponent->EquipClothing(OrdinaryClothing);
    }
}
