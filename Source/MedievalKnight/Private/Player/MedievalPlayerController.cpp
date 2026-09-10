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
        ArmingSword.ItemName = FText::FromString(TEXT("Épée d'armement"));
        ArmingSword.Description = FText::FromString(TEXT("Une épée à une main équilibrée en acier trempé."));
        ArmingSword.ItemType = EItemType::Weapon;
        ArmingSword.WeaponType = EWeaponType::Sword;
        ArmingSword.WeaponSubType = EWeaponSubType::ArmingSword;
        ArmingSword.Slot = EEquipmentSlot::MainHand;
        ArmingSword.BonusDamage = 0;
        ArmingSword.ValueInDenarii = 240;

        // 2. Un haubert de maille
        FArmor Chainmail;
        Chainmail.ItemID = TEXT("Chainmail_01");
        Chainmail.ItemName = FText::FromString(TEXT("Haubert de mailles"));
        Chainmail.Description = FText::FromString(TEXT("Protection solide en mailles d'acier rivetées."));
        Chainmail.ItemType = EItemType::Armor;
        Chainmail.ArmorType = EArmorType::Mail;
        Chainmail.Slot = EEquipmentSlot::ArmorMailPlate;
        Chainmail.ArmorProtection = 10;
        Chainmail.ValueInDenarii = 960;

        // 3. Un destrier
        FHorse Charger;
        Charger.ItemID = TEXT("Charger_01");
        Charger.ItemName = FText::FromString(TEXT("Bucephale"));
        Charger.Description = FText::FromString(TEXT("Un puissant destrier de guerre dressé pour la charge."));
        Charger.ItemType = EItemType::Mount;
        Charger.HorseType = EHorseType::Combat;
        Charger.HorseSubType = EHorseSubType::Charger;
        Charger.NaturalArmorProtection = 2;

        // Ajout à l'inventaire puis équipement direct
        InventoryComponent->AddWeapon(ArmingSword);
        InventoryComponent->AddArmor(Chainmail);
        InventoryComponent->AddMount(Charger);

        InventoryComponent->EquipWeapon(ArmingSword, EEquipmentSlot::MainHand);
        InventoryComponent->EquipArmor(Chainmail);
        InventoryComponent->EquipMount(Charger, EEquipmentSlot::WarMount);
    }
}
