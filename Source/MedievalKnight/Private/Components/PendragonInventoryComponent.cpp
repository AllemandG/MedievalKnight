#include "Components/PendragonInventoryComponent.h"

UPendragonInventoryComponent::UPendragonInventoryComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UPendragonInventoryComponent::AddItem(const FPendragonItem& Item)
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

void UPendragonInventoryComponent::AddWeapon(const FWeapon& Weapon)
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

void UPendragonInventoryComponent::AddArmor(const FArmor& Armor)
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

void UPendragonInventoryComponent::AddShield(const FShield& Shield)
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

void UPendragonInventoryComponent::AddMount(const FHorse& Mount)
{
    Mounts.Add(Mount);
    OnInventoryUpdated.Broadcast();
}

bool UPendragonInventoryComponent::RemoveItemByID(FName ItemID, int32 Quantity)
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

    return false;
}

bool UPendragonInventoryComponent::EquipWeapon(const FWeapon& Weapon, EEquipmentSlot TargetSlot)
{
    UnequipSlot(TargetSlot);

    FEquippedItemSlot NewSlot;
    NewSlot.Slot = TargetSlot;
    NewSlot.bIsOccupied = true;
    NewSlot.EquippedItemType = Weapon.ItemType;
    NewSlot.BaseItem = Weapon;
    NewSlot.EquippedWeapon = Weapon;

    EquippedSlots.Add(TargetSlot, NewSlot);
    RemoveItemByID(Weapon.ItemID, 1);
    OnInventoryUpdated.Broadcast();
    return true;
}

bool UPendragonInventoryComponent::EquipArmor(const FArmor& Armor)
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
        case EArmorType::Surcoat: SlotToUse = EEquipmentSlot::ArmorSurcoat; break;
        case EArmorType::Tabard:  SlotToUse = EEquipmentSlot::ArmorTabard; break;
        }
    }

    UnequipSlot(SlotToUse);

    FEquippedItemSlot NewSlot;
    NewSlot.Slot = SlotToUse;
    NewSlot.bIsOccupied = true;
    NewSlot.EquippedItemType = Armor.ItemType;
    NewSlot.BaseItem = Armor;
    NewSlot.EquippedArmor = Armor;

    EquippedSlots.Add(SlotToUse, NewSlot);
    RemoveItemByID(Armor.ItemID, 1);
    OnInventoryUpdated.Broadcast();
    return true;
}

bool UPendragonInventoryComponent::EquipShield(const FShield& Shield)
{
    UnequipSlot(EEquipmentSlot::OffHand);

    FEquippedItemSlot NewSlot;
    NewSlot.Slot = EEquipmentSlot::OffHand;
    NewSlot.bIsOccupied = true;
    NewSlot.EquippedItemType = Shield.ItemType;
    NewSlot.BaseItem = Shield;
    NewSlot.EquippedShield = Shield; // Un bouclier fournit de la protection comme une armure

    EquippedSlots.Add(EEquipmentSlot::OffHand, NewSlot);
    RemoveItemByID(Shield.ItemID, 1);
    OnInventoryUpdated.Broadcast();
    return true;
}

bool UPendragonInventoryComponent::EquipMount(const FHorse& Mount, EEquipmentSlot Slot)
{
    UnequipSlot(Slot);

    FEquippedItemSlot NewSlot;
    NewSlot.Slot = Slot;
    NewSlot.bIsOccupied = true;
    NewSlot.EquippedItemType = Mount.ItemType;
    NewSlot.BaseItem = Mount;
    NewSlot.EquippedHorse = Mount;

    EquippedSlots.Add(Slot, NewSlot);
    RemoveItemByID(Mount.ItemID, 1);
    OnInventoryUpdated.Broadcast();
    return true;
}

bool UPendragonInventoryComponent::UnequipSlot(EEquipmentSlot Slot)
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

    EquippedSlots.Remove(Slot);
    OnInventoryUpdated.Broadcast();
    return true;
}

bool UPendragonInventoryComponent::SwitchWeaponSlot(EEquipmentSlot FirstSlot, EEquipmentSlot SecondSlot)
{
    // Can only switch between melee weapons
    if ((FirstSlot != EEquipmentSlot::MainHand || FirstSlot != EEquipmentSlot::BeltMain || FirstSlot != EEquipmentSlot::BeltSecondary)
        && (SecondSlot != EEquipmentSlot::MainHand || SecondSlot != EEquipmentSlot::BeltMain || SecondSlot != EEquipmentSlot::BeltSecondary))
    {
        return false;
    }
    
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
        EquipWeapon(FirstWeapon, SecondSlot);
    }
    else
    {
        UnequipSlot(SecondSlot);
        EquipWeapon(SecondWeapon, FirstSlot);
    }

    OnInventoryUpdated.Broadcast();
    return true;
}

int32 UPendragonInventoryComponent::GetTotalKnightArmorProtection() const
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

int32 UPendragonInventoryComponent::GetActiveMountArmorProtection() const
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