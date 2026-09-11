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

        // Ajout à l'inventaire puis équipement direct
        InventoryComponent->AddWeapon(ArmingSword);
        InventoryComponent->AddArmor(Chainmail);
        InventoryComponent->AddMount(Charger);
    	InventoryComponent->AddArmor(Aketon);
    	InventoryComponent->AddArmor(NasalHelm);
    	InventoryComponent->AddShield(KiteShield);

        InventoryComponent->EquipWeapon(ArmingSword, EEquipmentSlot::MainHand);
        InventoryComponent->EquipArmor(Aketon);
        InventoryComponent->EquipMount(Charger, EEquipmentSlot::WarMount);
    	InventoryComponent->EquipArmor(Chainmail);
    }
}
