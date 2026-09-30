#include "MedievalKnight/Public/Player/MedievalPlayerController.h"

#include "Components/InventoryComponent.h"
#include "MedievalKnight/Public/Components/CharacterComponent.h"

AMedievalPlayerController::AMedievalPlayerController()
{
	// Instanciation automatique du composant sur le Controller
	CharacterComponent = CreateDefaultSubobject<UCharacterComponent>(TEXT("PendragonCharacterComponent"));
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("PendragonInventoryComponent"));
}

void AMedievalPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (InventoryComponent)
    {
		 // 3. Un destrier
	    FHorse Charger;
	    Charger.ItemID = TEXT("Bucephale_01");
	    Charger.ItemName = FText::FromString(TEXT("Bucephale"));
	    Charger.Description = FText::FromString(TEXT("The generic term for a combat-trained war horse; medium size, 15.2 hands."));
	    Charger.ItemType = EItemType::Mount;
	    Charger.HorseType = EHorseType::Combat;
	    Charger.HorseSubType = EHorseSubType::Charger;
    	Charger.Slot = EEquipmentSlot::WarMount;
    	Charger.HorseColor = EHorseColor::Chestnut;
	    Charger.ValueInDenarii = 1920;
    	

        // Ajout à l'inventaire puis équipement direct
        InventoryComponent->AddMount(Charger);

        InventoryComponent->EquipMount(Charger, EEquipmentSlot::WarMount);

    	if (InventoryComponent)
    	{
    		// Charger la Data Table depuis le Content Browser - /All/Game/Core/Items/DT_GeneralItems.DT_GeneralItems
    		UDataTable* GeneralItemTableObj = LoadObject<UDataTable>(nullptr,TEXT("/Game/Core/Items/DT_GeneralItems.DT_GeneralItems"));
    		if (GeneralItemTableObj)
    		{
    			// Liste des IDs de départ du chevalier
    			TArray<FName> DefaultGeneralItems = {
    				TEXT("OrdinaryClothes_01"), TEXT("WoolCloak_01"),TEXT("Cloak_01"), TEXT("KnightClothes_01"),
    				TEXT("SleepingBlanket_01"), TEXT("SleepingBlanket_01"), TEXT("CookingUtensils_01"), TEXT("FireKit_01"), TEXT("Bandage_01"),
    				TEXT("Panniers_01"), TEXT("SacksDrawstrings_01"), TEXT("LargeCanvasTarpaulin_01"), TEXT("PackSaddle_01"),
    				TEXT("RiddingSaddle_01"), TEXT("RiddingSaddle_01"), TEXT("WarSaddle_01"),
    				TEXT("HorseBlanket_01"), TEXT("HorseBlanket_01"), TEXT("HorseBlanket_01"), TEXT("HorseBlanket_01"), TEXT("FeedBag_01"),
    				TEXT("CurryingBrushes_01"), TEXT("Hobbles_01"), TEXT("HoofPick_01"), TEXT("HorseTowel_01"),	TEXT("Rope_01"),
    				TEXT("Chest_01"),
				};

    			// Initialisation en une seule ligne ! Fonctionne aussi pour un PNJ.
    			InventoryComponent->InitializeEquipmentFromDataTable(GeneralItemTableObj, DefaultGeneralItems);
    		}

    		UDataTable* ArmorsTableObj = LoadObject<UDataTable>(nullptr,TEXT("/Game/Core/Items/DT_Armors.DT_Armors"));
    		if (ArmorsTableObj)
    		{
    			TArray<FName> DefaultArmors = { TEXT("Aketon_01"), TEXT("Hauberk_01"), TEXT("NasalHelm_01") };
    			InventoryComponent->InitializeEquipmentFromDataTable(ArmorsTableObj, DefaultArmors);
    		}

    		UDataTable* ShieldsTableObj = LoadObject<UDataTable>(nullptr,TEXT("/Game/Core/Items/DT_Shields.DT_Shields"));
    		if (ShieldsTableObj)
    		{
    			TArray<FName> DefaultShields = { TEXT("KiteShield_01") };
    			InventoryComponent->InitializeEquipmentFromDataTable(ShieldsTableObj, DefaultShields);
    		}

    		UDataTable* HorsesTableObj = LoadObject<UDataTable>(nullptr,TEXT("/Game/Core/Items/DT_Horses.DT_Horses"));
    		if (HorsesTableObj)
    		{
    			TArray<FName> DefaultHorses = { TEXT("Rouncy_01"), TEXT("Sumpter_01") };
    			InventoryComponent->InitializeEquipmentFromDataTable(HorsesTableObj, DefaultHorses);
    		}

    		UDataTable* WeaponsTableObj = LoadObject<UDataTable>(nullptr,TEXT("/Game/Core/Items/DT_Weapons.DT_Weapons"));
    		if (WeaponsTableObj)
    		{
    			TArray<FName> DefaultWeapons = { TEXT("Spear_01"), TEXT("Spear_01"), TEXT("Spear_01"), TEXT("Spear_01"),
    				TEXT("Dagger_01"), TEXT("Lance_01"), TEXT("SelfBow_01"), TEXT("ArmingSword_01") };
    			InventoryComponent->InitializeEquipmentFromDataTable(WeaponsTableObj, DefaultWeapons);
    		}
    	}
    }

	FBlasonBorder Border;
	Border.bBorder = false;
	Border.Pattern = EBlasonPattern::Plain;
	Border.FirstColor = EBlasonColor::Brown;
	Border.PatternMultiplier = 1.08f;
	
	FBlasonSimpleDivision Content;
	Content.Division = EBlasonDivision::None;
	Content.FirstPart.Pattern = EBlasonPattern::Chequey;
	Content.FirstPart.FirstColor = EBlasonColor::Azure;
	Content.FirstPart.PatternMultiplier = 8.0f;
	Content.FirstPart.SecondColor = EBlasonColor::Or;

	FCharge Charge;
	Charge.ChargeType = EBlasonChargeType::Inanimate;
	Charge.InanimateCharge = EBlasonInanimateCharge::Tower;
	Charge.ChargeTincture = EBlasonColor::Gray;
	
	UBlason* Blason = NewObject<UBlason>();
	Blason->Border = Border;
	Blason->Content = Content;
	Blason->Charge = Charge;

	CharacterComponent->CoatOfArms = Blason;
}
