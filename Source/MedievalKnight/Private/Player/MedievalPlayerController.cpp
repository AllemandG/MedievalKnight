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
        ArmingSword.ItemName = FText::FromString(TEXT("Épée courte"));
        ArmingSword.Description = FText::FromString(TEXT("Une épée à une main équilibrée en acier trempé."));
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
        Chainmail.ItemName = FText::FromString(TEXT("Haubert de mailles"));
        Chainmail.Description = FText::FromString(TEXT("Protection solide en mailles d'acier rivetées."));
        Chainmail.ItemType = EItemType::Armor;
        Chainmail.ArmorType = EArmorType::Mail;
        Chainmail.Slot = EEquipmentSlot::ArmorMailPlate;
        Chainmail.ArmorProtection = 6;
        Chainmail.ValueInDenarii = 390;

        // 3. Un destrier
        FHorse Charger;
        Charger.ItemID = TEXT("Charger_01");
        Charger.ItemName = FText::FromString(TEXT("Bucephale"));
        Charger.Description = FText::FromString(TEXT("Un puissant destrier de guerre dressé pour la charge."));
        Charger.ItemType = EItemType::Mount;
        Charger.HorseType = EHorseType::Combat;
        Charger.HorseSubType = EHorseSubType::Charger;
    	Charger.ValueInDenarii = 1920;

    	// 4. Un Aketon
    	FArmor Aketon;
    	Aketon.ItemID = TEXT("Aketon_01");
    	Aketon.ItemName = FText::FromString(TEXT("Aketon"));
    	Aketon.Description = FText::FromString(TEXT("Protection textile rembourée portée sous une armure en mailles ou en plaques."));
    	Aketon.ItemType = EItemType::Armor;
    	Aketon.ArmorType = EArmorType::Textile;
    	Aketon.Slot = EEquipmentSlot::ArmorTextile;
    	Aketon.ArmorProtection = 2;
    	Aketon.ValueInDenarii = 15;

    	// 5. Un Nasal Helm
    	FArmor NasalHelm;
    	NasalHelm.ItemID = TEXT("NasalHelm_01");
    	NasalHelm.ItemName = FText::FromString(TEXT("Casque nasal"));
    	NasalHelm.Description = FText::FromString(TEXT("Un casque en acier avec protection nasale."));
    	NasalHelm.ItemType = EItemType::Armor;
    	NasalHelm.ArmorType = EArmorType::Helm;
    	NasalHelm.Slot = EEquipmentSlot::ArmorHelm;
    	NasalHelm.ArmorProtection = 2;
    	NasalHelm.ValueInDenarii = 90;

    	// 6. Un Bouclier
    	FShield KiteShield;
    	KiteShield.ItemID = TEXT("KiteShield_01");
    	KiteShield.ItemName = FText::FromString(TEXT("Bouclier Normand"));
    	KiteShield.Description = FText::FromString(TEXT("Un bouclier en amande."));
    	KiteShield.ItemType = EItemType::Shield;
    	KiteShield.ShieldType = EShieldType::Large;
    	KiteShield.Slot = EEquipmentSlot::OffHand;
    	KiteShield.ArmorProtection = 6;
    	KiteShield.ValueInDenarii = 30;

    	// 7. Une Arbalète légère
    	FWeapon CrossbowLight;
    	CrossbowLight.ItemID = TEXT("CrossbowLight_01");
    	CrossbowLight.ItemName = FText::FromString(TEXT("Arbalète Légère"));
    	CrossbowLight.Description = FText::FromString(TEXT("Une arbalète légère, nécessite d'être à pieds pour être rechargée."));
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
    	Dagger.ItemName = FText::FromString(TEXT("Dague"));
    	Dagger.Description = FText::FromString(TEXT("Une dague en acier trempé."));
    	Dagger.ItemType = EItemType::Weapon;
    	Dagger.WeaponType = EWeaponType::Thrown;
    	Dagger.WeaponAltType = EWeaponType::Brawling;
    	Dagger.WeaponSubType = EWeaponSubType::Dagger;
    	Dagger.Slot = EEquipmentSlot::BeltSecondary;
    	Dagger.FootMountedType = EFootMountedType::Both;
    	Dagger.BonusDamage = 2;
    	Dagger.ValueInDenarii = 20;

    	FWeapon Lance;
    	Lance.ItemID = TEXT("Lance_01");
    	Lance.ItemName = FText::FromString(TEXT("Lance"));
    	Lance.Description = FText::FromString(TEXT("Une Lance."));
    	Lance.ItemType = EItemType::Weapon;
    	Lance.WeaponType = EWeaponType::Charge;
    	Lance.WeaponSubType = EWeaponSubType::Lance;
    	Lance.Slot = EEquipmentSlot::MainHand;
    	Lance.FootMountedType = EFootMountedType::Mounted;
    	Lance.BonusDamage = 0;
    	Lance.ValueInDenarii = 30;

    	FWeapon JoustingLance;
    	JoustingLance.ItemID = TEXT("JoustingLance_01");
    	JoustingLance.ItemName = FText::FromString(TEXT("Lance de joutes"));
    	JoustingLance.Description = FText::FromString(TEXT("Une Lance de joutes, concue pour se briser plus facilement à l'impact."));
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
    	OrdinaryClothing.ItemName = FText::FromString(TEXT("Vêtements ordinaires"));
    	OrdinaryClothing.Description = FText::FromString(TEXT("Un set de vêtements ordinaires."));
    	OrdinaryClothing.ItemType = EItemType::Clothing;
    	OrdinaryClothing.ValueInDenarii = 30;

    	FPendragonItem FineClothing;
    	FineClothing.ItemID = TEXT("FineClothing_01");
    	FineClothing.ItemName = FText::FromString(TEXT("Vêtements de qualité"));
    	FineClothing.Description = FText::FromString(TEXT("Un set de vêtements d'une valeur de £1."));
    	FineClothing.ItemType = EItemType::Clothing;
    	FineClothing.ValueInDenarii = 240;

    	FPendragonItem NobleClothing;
    	FineClothing.ItemID = TEXT("NobleClothing_01");
    	FineClothing.ItemName = FText::FromString(TEXT("Atours de noble"));
    	FineClothing.Description = FText::FromString(TEXT("Un set de vêtements noble d'une valeur de £3."));
    	FineClothing.ItemType = EItemType::Clothing;
    	FineClothing.ValueInDenarii = 720;

    	FPendragonItem Cloak;
    	Cloak.ItemID = TEXT("Cloak_01");
    	Cloak.ItemName = FText::FromString(TEXT("Cape"));
    	Cloak.Description = FText::FromString(TEXT("Une cape pour se protéger des intempéries."));
    	Cloak.ItemType = EItemType::Clothing;
    	Cloak.ValueInDenarii = 5;

    	FPendragonItem WoolCloak;
    	WoolCloak.ItemID = TEXT("WoolCloak_01");
    	WoolCloak.ItemName = FText::FromString(TEXT("Cape"));
    	WoolCloak.Description = FText::FromString(TEXT("Une cape en laine pour se protéger du froid."));
    	WoolCloak.ItemType = EItemType::Clothing;
    	WoolCloak.ValueInDenarii = 10;

    	FPendragonItem TravelGear;
    	TravelGear.ItemID = TEXT("TravelGear_01");
    	TravelGear.ItemName = FText::FromString(TEXT("Équipement de voyage"));
    	TravelGear.Description = FText::FromString(TEXT("Deux couvertures et des serviettes ; ustensiles de cuisine et de repas ; nécessaire pour faire du feu ; pansements ; une paire de sacoches ; plusieurs sacs à cordon pour tout ranger ; une grande bâche en toile ; un bât pour le transport de charge et des sacoches."));
    	TravelGear.ItemType = EItemType::General;
    	TravelGear.ValueInDenarii = 120;

    	FPendragonItem HorseGear;
    	HorseGear.ItemID = TEXT("HorseGear_01");
    	HorseGear.ItemName = FText::FromString(TEXT("Équipement pour chevaux"));
    	HorseGear.Description = FText::FromString(TEXT("Deux selles de monte et leur harnachement ; une selle de guerre et son harnachement ; quatre couvertures pour chevaux ; un sac à fourrage ; des étrilles et brosses ; des entraves ; un cure-pied ; des serviettes pour chevaux ; corde."));
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
    	InventoryComponent->EquipWeapon(Dagger, EEquipmentSlot::BeltSecondary);
    	InventoryComponent->EquipWeapon(Lance, EEquipmentSlot::JoustingWeapon);

    	FEquippedItemSlot NewSlot;
    	NewSlot.Slot = EEquipmentSlot::Clothing;
    	NewSlot.bIsOccupied = true;
    	NewSlot.EquippedItemType = OrdinaryClothing.ItemType;
    	NewSlot.BaseItem = OrdinaryClothing;
    	InventoryComponent->EquippedSlots.Add(EEquipmentSlot::Clothing, NewSlot);
    }
}
