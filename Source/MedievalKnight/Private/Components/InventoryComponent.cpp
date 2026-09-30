#include "Components/InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::InitializeDefaultKnightEquipment()
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
    ArmingSword.IconTexturePath = TEXT("Texture2D'/Game/Assets/Textures/items/01_weapons/arming_sword_01.arming_sword_01'");
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
    Chainmail.IconTexturePath = TEXT("Texture2D'/Game/Assets/Textures/items/02_armors/hauberk_01.hauberk_01'");
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
    Charger.Slot = EEquipmentSlot::WarMount;
    Charger.IconTexturePath = TEXT("Texture2D'/Game/Assets/Textures/items/04_mounts/horse_01.horse_01'");
    Charger.ValueInDenarii = 1920;

    // 4. Un Aketon
    FArmor Aketon;
    Aketon.ItemID = TEXT("Aketon_01");
    Aketon.ItemName = FText::FromString(TEXT("Aketon"));
    Aketon.Description = FText::FromString(TEXT("Padded textile protection worn under mail or plate armor."));
    Aketon.ItemType = EItemType::Armor;
    Aketon.ArmorType = EArmorType::Textile;
    Aketon.Slot = EEquipmentSlot::ArmorTextile;
    Aketon.IconTexturePath = TEXT("Texture2D'/Game/Assets/Textures/items/02_armors/aketon_01.aketon_01'");
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
    NasalHelm.IconTexturePath = TEXT("Texture2D'/Game/Assets/Textures/items/02_armors/nasal_helm_01.nasal_helm_01'");
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
    KiteShield.IconTexturePath = TEXT("Texture2D'/Game/Assets/Textures/items/03_shields/kite_shield_01.kite_shield_01'");
    KiteShield.ArmorProtection = 6;
    KiteShield.ValueInDenarii = 30;

    // Autres
    FWeapon Dagger;
    Dagger.ItemID = TEXT("Dagger_01");
    Dagger.ItemName = FText::FromString(TEXT("Dagger"));
    Dagger.Description = FText::FromString(TEXT("A tempered steel dagger."));
    Dagger.ItemType = EItemType::Weapon;
    Dagger.WeaponType = EWeaponType::Brawling;
    Dagger.WeaponAltType = EWeaponType::Thrown;
    Dagger.WeaponSubType = EWeaponSubType::Dagger;
    Dagger.Slot = EEquipmentSlot::Dagger;
    Dagger.FootMountedType = EFootMountedType::Both;
    Dagger.IconTexturePath = TEXT("Texture2D'/Game/Assets/Textures/items/01_weapons/dagger_01.dagger_01'");
    Dagger.BonusDamage = 2;
    Dagger.ValueInDenarii = 20;

    FWeapon Lance;
    Lance.ItemID = TEXT("Lance_01");
    Lance.ItemName = FText::FromString(TEXT("Lance"));
    Lance.Description = FText::FromString(TEXT("A long wooden spear weapon designed specifically for high-impact mounted charges."));
    Lance.ItemType = EItemType::Weapon;
    Lance.WeaponType = EWeaponType::Charge;
    Lance.WeaponSubType = EWeaponSubType::Lance;
    Lance.Slot = EEquipmentSlot::JoustingWeapon;
    Lance.FootMountedType = EFootMountedType::Mounted;
    Lance.IconTexturePath = TEXT("Texture2D'/Game/Assets/Textures/items/01_weapons/lance_01.lance_01'");
    Lance.BonusDamage = 0;
    Lance.ValueInDenarii = 30;

    // General Items
	FPendragonItem OrdinaryClothing;
    OrdinaryClothing.ItemID = TEXT("OrdinaryClothing_01");
    OrdinaryClothing.ItemName = FText::FromString(TEXT("Ordinary Clothes"));
    OrdinaryClothing.Description = FText::FromString(TEXT("A set of ordinary clothes."));
    OrdinaryClothing.ItemType = EItemType::Clothing;
    OrdinaryClothing.Slot = EEquipmentSlot::Clothing;
    OrdinaryClothing.IconTexturePath = TEXT("Texture2D'/Game/Assets/Textures/items/05_general/clothes_ordinary_01.clothes_ordinary_01'");
    OrdinaryClothing.ValueInDenarii = 30;

    FPendragonItem FineClothing;
    FineClothing.ItemID = TEXT("FineClothing_01");
    FineClothing.ItemName = FText::FromString(TEXT("Fine Clothes"));
    FineClothing.Description = FText::FromString(TEXT("A set of clothes worth £1."));
    FineClothing.ItemType = EItemType::Clothing;
    FineClothing.Slot = EEquipmentSlot::Clothing;
    FineClothing.IconTexturePath = TEXT("Texture2D'/Game/Assets/Textures/items/05_general/clothes_knight_01.clothes_knight_01'");
    FineClothing.ValueInDenarii = 240;

    FPendragonItem Cloak;
    Cloak.ItemID = TEXT("Cloak_01");
    Cloak.ItemName = FText::FromString(TEXT("Cloak"));
    Cloak.Description = FText::FromString(TEXT("A cape to protect against the elements."));
    Cloak.ItemType = EItemType::Clothing;
    Cloak.Slot = EEquipmentSlot::Cape;
    Cloak.IconTexturePath = TEXT("Texture2D'/Game/Assets/Textures/items/05_general/cloak_01.cloak_01'");
    Cloak.ValueInDenarii = 5;

    FPendragonItem WoolCloak;
    WoolCloak.ItemID = TEXT("WoolCloak_01");
    WoolCloak.ItemName = FText::FromString(TEXT("Wool Cloak"));
    WoolCloak.Description = FText::FromString(TEXT("A wool cape to protect against the cold."));
    WoolCloak.ItemType = EItemType::Clothing;
    WoolCloak.Slot = EEquipmentSlot::Cape;
    WoolCloak.IconTexturePath = TEXT("Texture2D'/Game/Assets/Textures/items/05_general/wool_cloak_01.wool_cloak_01'");
    WoolCloak.ValueInDenarii = 10;

    FPendragonItem TravelGear;
    TravelGear.ItemID = TEXT("TravelGear_01");
    TravelGear.ItemName = FText::FromString(TEXT("Travel Gear"));
    TravelGear.Description = FText::FromString(TEXT("Two sleeping blankets and towels; eating and cooking utensils; fire-making kit; bandages; pair of panniers; several sacks with drawstrings to store everything; large canvas tarpaulin; pack frame for sumpter and saddlebags"));
    TravelGear.ItemType = EItemType::General;
    TravelGear.IconTexturePath = TEXT("Texture2D'/Game/Assets/Textures/items/05_general/travel_gear_01.travel_gear_01'");
    TravelGear.ValueInDenarii = 120;

    FPendragonItem HorseGear;
    HorseGear.ItemID = TEXT("HorseGear_01");
    HorseGear.ItemName = FText::FromString(TEXT("Horse Gear"));
    HorseGear.Description = FText::FromString(TEXT("Two ridding saddles and tack; One War saddle and tack; Four horse blankets; Feed bag; Currying brushes; Hobbles; Hoof pick; Horse towels; Rope"));
    HorseGear.ItemType = EItemType::General;
    HorseGear.IconTexturePath = TEXT("Texture2D'/Game/Assets/Textures/items/05_general/horseshoe_01.horseshoe_01'");
    HorseGear.ValueInDenarii = 120;

    // Clear équipement existant
    EquippedSlots.Empty();

    // Ajout à l'inventaire puis équipement direct
    AddWeapon(ArmingSword);
    AddArmor(Chainmail);
    AddMount(Charger);
    AddArmor(Aketon);
    AddArmor(NasalHelm);
    AddShield(KiteShield);
    AddWeapon(Dagger);
    AddWeapon(Lance);
    AddItem(OrdinaryClothing);
    AddItem(FineClothing);
    AddItem(Cloak);
    AddItem(WoolCloak);
    AddItem(TravelGear);
    AddItem(HorseGear);

    EquipWeapon(ArmingSword, EEquipmentSlot::MainHand);
    EquipMount(Charger, EEquipmentSlot::WarMount);
    EquipArmor(Aketon);
    EquipArmor(Chainmail);
    EquipArmor(NasalHelm);
    EquipShield(KiteShield);
    EquipWeapon(Dagger, EEquipmentSlot::Dagger);
    EquipWeapon(Lance, EEquipmentSlot::JoustingWeapon);
    EquipClothing(OrdinaryClothing, EEquipmentSlot::Clothing);
    EquipClothing(Cloak, EEquipmentSlot::Cape);
    
}

void UInventoryComponent::InitializeEquipmentFromDataTable(UDataTable* ItemDataTable,
    const TArray<FName>& ItemsToGiveAndEquip)
{
    if (!ItemDataTable) return;

    for (const FName& ItemID : ItemsToGiveAndEquip)
    {
        // 1. Sécurité : ignorer les noms vides pour éviter les crashs
        if (ItemID.IsNone())
        {
            continue;
        }

        FString ContextString = TEXT("InitializeEquipment");
        
        if (FWeapon* WeaponRow = ItemDataTable->FindRow<FWeapon>(ItemID, ContextString, false))
        {
            AddWeapon(*WeaponRow);
            EquipWeapon(*WeaponRow, WeaponRow->Slot);
        }
        else if (FArmor* ArmorRow = ItemDataTable->FindRow<FArmor>(ItemID, ContextString, false))
        {
            AddArmor(*ArmorRow);
            EquipArmor(*ArmorRow);
        }
        else if (FShield* ShieldRow = ItemDataTable->FindRow<FShield>(ItemID, ContextString, false))
        {
            AddShield(*ShieldRow);
            EquipShield(*ShieldRow);
        }
        else if (FHorse* MountRow = ItemDataTable->FindRow<FHorse>(ItemID, ContextString, false))
        {
            AddMount(*MountRow);
            EquipMount(*MountRow, MountRow->Slot);
        }
        else if (FHorseArmor* HorseArmorRow = ItemDataTable->FindRow<FHorseArmor>(ItemID, ContextString, false))
        {
            AddHorseArmor(*HorseArmorRow);
        }
        else if (FPendragonItem* ItemRow = ItemDataTable->FindRow<FPendragonItem>(ItemID, ContextString, false))
        {
            AddItem(*ItemRow);
            
            // Si c'est un vêtement ou une cape, on peut l'équiper selon son slot
            if (ItemRow->ItemType == EItemType::Clothing)
            {
                EquipClothing(*ItemRow, ItemRow->Slot);
            }
        }
    }
}

void UInventoryComponent::AddItem(const FPendragonItem& Item)
{
    for (FPendragonItem& Existing : GeneralItems)
    {
        if (Existing.ItemID == Item.ItemID)
        {
            Existing.Quantity += Item.Quantity;
            OnInventoryUpdated.Broadcast();
            return;
        }
    }
    GeneralItems.Add(Item);
    OnInventoryUpdated.Broadcast();
}

void UInventoryComponent::AddWeapon(const FWeapon& Weapon)
{
    for (FWeapon& Existing : Weapons)
    {
        if (Existing.ItemID == Weapon.ItemID)
        {
            Existing.Quantity += Weapon.Quantity;
            OnInventoryUpdated.Broadcast();
            return;
        }
    }
    Weapons.Add(Weapon);
    OnInventoryUpdated.Broadcast();
}

void UInventoryComponent::AddArmor(const FArmor& Armor)
{
    for (FArmor& Existing : Armors)
    {
        if (Existing.ItemID == Armor.ItemID)
        {
            Existing.Quantity += Armor.Quantity;
            OnInventoryUpdated.Broadcast();
            return;
        }
    }
    Armors.Add(Armor);
    OnInventoryUpdated.Broadcast();
}

void UInventoryComponent::AddShield(const FShield& Shield)
{
    for (FShield& Existing : Shields)
    {
        if (Existing.ItemID == Shield.ItemID)
        {
            Existing.Quantity += Shield.Quantity;
            OnInventoryUpdated.Broadcast();
            return;
        }
    }
    Shields.Add(Shield);
    OnInventoryUpdated.Broadcast();
}

void UInventoryComponent::AddMount(const FHorse& Mount)
{
    Mounts.Add(Mount);
    OnInventoryUpdated.Broadcast();
}

void UInventoryComponent::AddHorseArmor(const FHorseArmor& Mount)
{
    for (FHorseArmor& Existing : HorseArmors)
    {
        if (Existing.ItemID == Mount.ItemID)
        {
            Existing.Quantity += Mount.Quantity;
            OnInventoryUpdated.Broadcast();
            return;
        }
    }
    HorseArmors.Add(Mount);
    OnInventoryUpdated.Broadcast();
}

bool UInventoryComponent::RemoveItemByID(FName ItemID, int32 Quantity)
{
    // Recherche dans les objets généraux
    for (int32 Index = 0; Index < GeneralItems.Num(); ++Index)
    {
        if (GeneralItems[Index].ItemID == ItemID)
        {
            GeneralItems[Index].Quantity -= Quantity;
            if (GeneralItems[Index].Quantity <= 0) GeneralItems.RemoveAt(Index);
            OnInventoryUpdated.Broadcast();
            return true;
        }
    }

    // Recherche dans les armes
    for (int32 Index = 0; Index < Weapons.Num(); ++Index)
    {
        if (Weapons[Index].ItemID == ItemID)
        {
            Weapons[Index].Quantity -= Quantity;
            if (Weapons[Index].Quantity <= 0) Weapons.RemoveAt(Index);
            OnInventoryUpdated.Broadcast();
            return true;
        }
    }

    // Recherche dans les armures
    for (int32 Index = 0; Index < Armors.Num(); ++Index)
    {
        if (Armors[Index].ItemID == ItemID)
        {
            Armors[Index].Quantity -= Quantity;
            if (Armors[Index].Quantity <= 0) Armors.RemoveAt(Index);
            OnInventoryUpdated.Broadcast();
            return true;
        }
    }

    // Recherche dans les boucliers
    for (int32 Index = 0; Index < Shields.Num(); ++Index)
    {
        if (Shields[Index].ItemID == ItemID)
        {
            Shields[Index].Quantity -= Quantity;
            if (Shields[Index].Quantity <= 0) Shields.RemoveAt(Index);
            OnInventoryUpdated.Broadcast();
            return true;
        }
    }

    // Recherche dans les montures
    for (int32 Index = 0; Index < Mounts.Num(); ++Index)
    {
        if (Mounts[Index].ItemID == ItemID)
        {
            Mounts.RemoveAt(Index);
            OnInventoryUpdated.Broadcast();
            return true;
        }
    }

    // Recherche dans les armures pour montures
    for (int32 Index = 0; Index < HorseArmors.Num(); ++Index)
    {
        if (HorseArmors[Index].ItemID == ItemID)
        {
            HorseArmors[Index].Quantity -= Quantity;
            HorseArmors.RemoveAt(Index);
            OnInventoryUpdated.Broadcast();
            return true;
        }
    }

    return false;
}

bool UInventoryComponent::EquipWeapon(const FWeapon& Weapon, EEquipmentSlot TargetSlot)
{
    if (Weapon.TwoHanded)
    {
        UnequipSlot(EEquipmentSlot::OffHand);
    }
    
    UnequipSlot(TargetSlot);

    FEquippedItemSlot NewSlot;
    NewSlot.Slot = TargetSlot;
    NewSlot.bIsOccupied = true;
    NewSlot.EquippedItemType = Weapon.ItemType;
    NewSlot.EquippedWeapon = Weapon;
    NewSlot.EquippedWeapon.Quantity = 1;

    EquippedSlots.Add(TargetSlot, NewSlot);
    RemoveItemByID(Weapon.ItemID, 1);
    OnInventoryUpdated.Broadcast();
    return true;
}

bool UInventoryComponent::EquipArmor(const FArmor& Armor)
{
    EEquipmentSlot SlotToUse = Armor.Slot;

    // Détermination de l'emplacement selon le type d'armure si non renseigné
    if (SlotToUse == EEquipmentSlot::None)
    {
        switch (Armor.ArmorType)
        {
        case EArmorType::Textile: SlotToUse = EEquipmentSlot::ArmorTextile; break;
        case EArmorType::Mail:
        case EArmorType::Plate:   SlotToUse = EEquipmentSlot::ArmorMailPlate; break;
        case EArmorType::Helm:    SlotToUse = EEquipmentSlot::ArmorHelm; break;
        case EArmorType::Tabard:  SlotToUse = EEquipmentSlot::ArmorTabard; break;
        }
    }

    UnequipSlot(SlotToUse);

    FEquippedItemSlot NewSlot;
    NewSlot.Slot = SlotToUse;
    NewSlot.bIsOccupied = true;
    NewSlot.EquippedItemType = Armor.ItemType;
    NewSlot.EquippedArmor = Armor;
    NewSlot.EquippedArmor.Quantity = 1;

    EquippedSlots.Add(SlotToUse, NewSlot);
    RemoveItemByID(Armor.ItemID, 1);
    OnInventoryUpdated.Broadcast();
    return true;
}

bool UInventoryComponent::EquipShield(const FShield& Shield)
{
    if (EquippedSlots.Contains(EEquipmentSlot::MainHand))
    {
        FEquippedItemSlot OccupiedSlot = EquippedSlots[EEquipmentSlot::MainHand];
        if (OccupiedSlot.EquippedWeapon.TwoHanded)
        {
            UnequipSlot(EEquipmentSlot::MainHand);
        }
    }
    
    UnequipSlot(EEquipmentSlot::OffHand);

    FEquippedItemSlot NewSlot;
    NewSlot.Slot = EEquipmentSlot::OffHand;
    NewSlot.bIsOccupied = true;
    NewSlot.EquippedItemType = Shield.ItemType;
    NewSlot.EquippedShield = Shield; // Un bouclier fournit de la protection comme une armure
    NewSlot.EquippedShield.Quantity = 1;
    
    EquippedSlots.Add(EEquipmentSlot::OffHand, NewSlot);
    RemoveItemByID(Shield.ItemID, 1);
    OnInventoryUpdated.Broadcast();
    return true;
}

bool UInventoryComponent::EquipMount(const FHorse& Mount, EEquipmentSlot Slot)
{
    UnequipSlot(Slot);

    FEquippedItemSlot NewSlot;
    NewSlot.Slot = Slot;
    NewSlot.bIsOccupied = true;
    NewSlot.EquippedItemType = Mount.ItemType;
    NewSlot.EquippedHorse = Mount;

    EquippedSlots.Add(Slot, NewSlot);
    RemoveItemByID(Mount.ItemID, 1);
    OnInventoryUpdated.Broadcast();
    return true;
}

bool UInventoryComponent::EquipClothing(const FPendragonItem& Item, EEquipmentSlot Slot)
{
    UnequipSlot(Slot);

    FEquippedItemSlot NewSlot;
    NewSlot.Slot = Slot;
    NewSlot.bIsOccupied = true;
    NewSlot.EquippedItemType = Item.ItemType;
    NewSlot.BaseItem = Item;
    NewSlot.BaseItem.Quantity = 1;

    EquippedSlots.Add(Slot, NewSlot);
    RemoveItemByID(Item.ItemID, 1);
    OnInventoryUpdated.Broadcast();
    return true;
}

bool UInventoryComponent::UnequipSlot(EEquipmentSlot Slot)
{
    if (!EquippedSlots.Contains(Slot))
    {
        return false;
    }

    FEquippedItemSlot OccupiedSlot = EquippedSlots[Slot];

    // Restitution dans le sac à backpack selon le type
    if (OccupiedSlot.EquippedWeapon.ItemID != NAME_None)
    {
        AddWeapon(OccupiedSlot.EquippedWeapon);
    }
    else if (OccupiedSlot.EquippedHorse.ItemID != NAME_None)
    {
        AddMount(OccupiedSlot.EquippedHorse);
    }
    else if (OccupiedSlot.EquippedShield.ItemID != NAME_None)
    {
        AddShield(OccupiedSlot.EquippedShield);
    }
    else if (OccupiedSlot.EquippedArmor.ItemID != NAME_None)
    {
        AddArmor(OccupiedSlot.EquippedArmor);
    }
    else if (OccupiedSlot.BaseItem.ItemID != NAME_None)
    {
        AddItem(OccupiedSlot.BaseItem);
    }

    EquippedSlots.Remove(Slot);
    OnInventoryUpdated.Broadcast();
    return true;
}

bool UInventoryComponent::SwitchWeaponSlot(EEquipmentSlot FirstSlot, EEquipmentSlot SecondSlot)
{
    // Can only switch between melee weapons
    if ((FirstSlot != EEquipmentSlot::MainHand || FirstSlot != EEquipmentSlot::Dagger || FirstSlot != EEquipmentSlot::Belt1 || FirstSlot != EEquipmentSlot::Belt2)
        && (SecondSlot != EEquipmentSlot::MainHand || SecondSlot != EEquipmentSlot::Dagger || SecondSlot != EEquipmentSlot::Belt1 || SecondSlot != EEquipmentSlot::Belt2))
    {
        return false;
    }

    // No slot has an equipped weapon
    if (!EquippedSlots.Contains(FirstSlot) || !EquippedSlots.Contains(SecondSlot))
    {
        return false;
    }
    
    FEquippedItemSlot FirstOccupiedSlot = EquippedSlots[FirstSlot];
    FEquippedItemSlot SecondOccupiedSlot = EquippedSlots[SecondSlot];
    
    FWeapon FirstWeapon = FirstOccupiedSlot.EquippedWeapon;
    FWeapon SecondWeapon = SecondOccupiedSlot.EquippedWeapon;

    if (FirstOccupiedSlot.EquippedWeapon.ItemID != NAME_None && SecondOccupiedSlot.EquippedWeapon.ItemID != NAME_None)
    {
        UnequipSlot(FirstSlot);
        UnequipSlot(SecondSlot);
        EquipWeapon(FirstWeapon, SecondSlot);
        EquipWeapon(SecondWeapon, FirstSlot);
    }
    else if (FirstOccupiedSlot.EquippedWeapon.ItemID != NAME_None)
    {
        UnequipSlot(FirstSlot);
        UnequipSlot(SecondSlot);
        EquipWeapon(FirstWeapon, SecondSlot);
    }
    else
    {
        UnequipSlot(FirstSlot);
        UnequipSlot(SecondSlot);
        EquipWeapon(SecondWeapon, FirstSlot);
    }

    OnInventoryUpdated.Broadcast();
    return true;
}

bool UInventoryComponent::EquipHorseArmor(const FHorseArmor& HorseArmor, EEquipmentSlot HorseSlot)
{
    if (!EquippedSlots.Contains(HorseSlot))
    {
        return false;
    }

    if (HorseArmor.HorseArmorType == EHorseArmorType::CaparisonFull || HorseArmor.HorseArmorType == EHorseArmorType::CaparisonHalf || HorseArmor.HorseArmorType == EHorseArmorType::CaparisonOpen)
    {
        if (EquippedSlots.Find(HorseSlot)->EquippedHorse.Caparison.ItemID != NAME_None)
        {
            AddHorseArmor(EquippedSlots.Find(HorseSlot)->EquippedHorse.Caparison);
        }
        EquippedSlots.Find(HorseSlot)->EquippedHorse.Caparison = HorseArmor;
        EquippedSlots.Find(HorseSlot)->EquippedHorse.Caparison.Quantity = 1;
    }
    else if (HorseArmor.HorseArmorType == EHorseArmorType::GambesonFull || HorseArmor.HorseArmorType == EHorseArmorType::GambesonHalf || HorseArmor.HorseArmorType == EHorseArmorType::PaddingFull)
    {
        if (EquippedSlots.Find(HorseSlot)->EquippedHorse.HorseArmor.ItemID != NAME_None)
        {
            AddHorseArmor(EquippedSlots.Find(HorseSlot)->EquippedHorse.HorseArmor);
        }
        EquippedSlots.Find(HorseSlot)->EquippedHorse.HorseArmor = HorseArmor;
        EquippedSlots.Find(HorseSlot)->EquippedHorse.HorseArmor.Quantity = 1;
    }
    else
    {
        return false;
    }
    
    RemoveItemByID(HorseArmor.ItemID, 1);
    OnInventoryUpdated.Broadcast();
    return true;
}

bool UInventoryComponent::UnequipHorseArmor(FName ItemID, EEquipmentSlot HorseSlot)
{
    if (!EquippedSlots.Contains(HorseSlot))
    {
        return false;
    }

    if (EquippedSlots.Find(HorseSlot)->EquippedHorse.Caparison.ItemID == ItemID)
    {
        AddHorseArmor(EquippedSlots.Find(HorseSlot)->EquippedHorse.Caparison);
        EquippedSlots.Find(HorseSlot)->EquippedHorse.Caparison.ItemID = NAME_None;
    }
    else if (EquippedSlots.Find(HorseSlot)->EquippedHorse.HorseArmor.ItemID == ItemID)
    {
        AddHorseArmor(EquippedSlots.Find(HorseSlot)->EquippedHorse.HorseArmor);
        EquippedSlots.Find(HorseSlot)->EquippedHorse.HorseArmor.ItemID = NAME_None;
        EquippedSlots.Find(HorseSlot)->EquippedHorse.HorseArmor.ArmorProtection = 0;
    }
    return true;
}

int32 UInventoryComponent::GetTotalKnightArmorProtection() const
{
    int32 TotalProtection = 0;

    for (const auto& Pair : EquippedSlots)
    {
        const FEquippedItemSlot& SlotData = Pair.Value;
        
        // Exclut les montures du calcul de protection du chevalier
        if (SlotData.Slot != EEquipmentSlot::WarMount && SlotData.Slot != EEquipmentSlot::RidingMount)
        {
            TotalProtection += SlotData.EquippedArmor.ArmorProtection;
            TotalProtection += SlotData.EquippedShield.ArmorProtection;
        }
    }

    return TotalProtection;
}

int32 UInventoryComponent::GetActiveMountArmorProtection() const
{
    if (const FEquippedItemSlot* WarMountSlot = EquippedSlots.Find(EEquipmentSlot::WarMount))
    {
        return WarMountSlot->EquippedHorse.GetArmorProtection();
    }
    
    if (const FEquippedItemSlot* RidingHorseSlot = EquippedSlots.Find(EEquipmentSlot::RidingMount))
    {
        return RidingHorseSlot->EquippedHorse.GetArmorProtection();
    }
    
    return 0;
}