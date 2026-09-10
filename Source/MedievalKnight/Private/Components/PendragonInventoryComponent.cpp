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
    EquippedWeapon = Weapon;
    EquippedItems.Add(TargetSlot, Weapon);
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
    EquippedArmors.Add(SlotToUse, Armor);
    EquippedItems.Add(SlotToUse, Armor);
    RemoveItemByID(Armor.ItemID, 1);
    OnInventoryUpdated.Broadcast();
    return true;
}

bool UPendragonInventoryComponent::EquipShield(const FShield& Shield)
{
    UnequipSlot(EEquipmentSlot::OffHand);
    EquippedShield = Shield;
    EquippedItems.Add(EEquipmentSlot::OffHand, Shield);
    RemoveItemByID(Shield.ItemID, 1);
    OnInventoryUpdated.Broadcast();
    return true;
}

bool UPendragonInventoryComponent::EquipMount(const FHorse& Mount, EEquipmentSlot Slot)
{
    UnequipSlot(Slot);
    EquippedWarMount = Mount;
    EquippedItems.Add(Slot, Mount);
    RemoveItemByID(Mount.ItemID, 1);
    OnInventoryUpdated.Broadcast();
    return true;
}

bool UPendragonInventoryComponent::UnequipSlot(EEquipmentSlot Slot)
{
    bool bUnequippedAny = false;

    if (EquippedArmors.Contains(Slot))
    {
        AddArmor(EquippedArmors[Slot]);
        EquippedArmors.Remove(Slot);
        bUnequippedAny = true;
    }

    if (Slot == EEquipmentSlot::MainHand && EquippedWeapon.ItemID != NAME_None)
    {
        AddWeapon(EquippedWeapon);
        EquippedWeapon = FWeapon();
        bUnequippedAny = true;
    }

    if (Slot == EEquipmentSlot::OffHand && EquippedShield.ItemID != NAME_None)
    {
        AddShield(EquippedShield);
        EquippedShield = FShield();
        bUnequippedAny = true;
    }

    if (Slot == EEquipmentSlot::WarMount && EquippedWarMount.ItemID != NAME_None)
    {
        AddMount(EquippedWarMount);
        EquippedWarMount = FHorse();
        bUnequippedAny = true;
    }

    if (EquippedItems.Contains(Slot))
    {
        EquippedItems.Remove(Slot);
        bUnequippedAny = true;
    }

    if (bUnequippedAny)
    {
        OnInventoryUpdated.Broadcast();
    }

    return bUnequippedAny;
}

int32 UPendragonInventoryComponent::GetTotalKnightArmorProtection() const
{
    int32 TotalProtection = 0;

    // Somme des armures superposées (ex: Gambison textile + Haubert de maille + Casque)
    for (const auto& Pair : EquippedArmors)
    {
        TotalProtection += Pair.Value.ArmorProtection;
    }

    // Ajout du bouclier s'il est équipé
    if (EquippedShield.ItemID != NAME_None)
    {
        TotalProtection += EquippedShield.ArmorProtection;
    }

    return TotalProtection;
}

int32 UPendragonInventoryComponent::GetActiveMountArmorProtection() const
{
    if (EquippedWarMount.ItemID != NAME_None)
    {
        return EquippedWarMount.GetArmorProtection();
    }
    return 0;
}