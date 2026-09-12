#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Items/InventoryTypes.h"
#include "PendragonInventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MEDIEVALKNIGHT_API UPendragonInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UPendragonInventoryComponent();

    UPROPERTY(BlueprintAssignable, Category = "Pendragon|Inventory")
    FOnInventoryUpdated OnInventoryUpdated;

    // Inventaire général (Objets divers, consommables, vêtements, etc.)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Inventory")
    TArray<FPendragonItem> GeneralItems;

    // Listes typées pour préserver les métadonnées spécifiques
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Inventory|Weapons")
    TArray<FWeapon> Weapons;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Inventory|Armors")
    TArray<FArmor> Armors;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Inventory|Shields")
    TArray<FShield> Shields;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Inventory|Mounts")
    TArray<FHorse> Mounts;

    // Remplacement de TMap<EEquipmentSlot, FPendragonItem>
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment")
    TMap<EEquipmentSlot, FEquippedItemSlot> EquippedSlots;

    // Monnaie (en deniers - 240 deniers = 1 livre/pound)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Economy")
    int32 Denarii = 240;

    /** Équipe le personnage avec le trousseau de départ standard d'un chevalier */
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Inventory")
    void InitializeDefaultKnightEquipment();
    
    // --- Fonctions d'ajout/retrait de base ---

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Inventory")
    void AddItem(const FPendragonItem& Item);

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Inventory")
    void AddWeapon(const FWeapon& Weapon);

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Inventory")
    void AddArmor(const FArmor& Armor);

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Inventory")
    void AddShield(const FShield& Shield);

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Inventory")
    void AddMount(const FHorse& Mount);

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Inventory")
    bool RemoveItemByID(FName ItemID, int32 Quantity = 1);

    // --- Équipement & Déséquipement ---

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Equipment")
    bool EquipWeapon(const FWeapon& Weapon, EEquipmentSlot TargetSlot = EEquipmentSlot::MainHand);

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Equipment")
    bool EquipArmor(const FArmor& Armor);

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Equipment")
    bool EquipShield(const FShield& Shield);

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Equipment")
    bool EquipMount(const FHorse& Mount, EEquipmentSlot Slot = EEquipmentSlot::WarMount);

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Equipment")
    bool EquipClothing(const FPendragonItem& Item, EEquipmentSlot Slot = EEquipmentSlot::Clothing);

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Equipment")
    bool UnequipSlot(EEquipmentSlot Slot);

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Equipment")
    bool SwitchWeaponSlot(EEquipmentSlot FirstSlot, EEquipmentSlot SecondSlot);

    // --- Calculs de Statistiques ---

    // Calcule la protection d'armure totale cumulée (Armure textile + Maille/Plaque + Casque + Surcot + Bouclier)
    UFUNCTION(BlueprintPure, Category = "Pendragon|Equipment")
    int32 GetTotalKnightArmorProtection() const;

    // Calcule la protection d'armure de la monture active
    UFUNCTION(BlueprintPure, Category = "Pendragon|Equipment")
    int32 GetActiveMountArmorProtection() const;
};