#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MedievalKnight/Public/Core/PendragonEnums.h"
#include "MedievalKnight/Public/Core/PendragonTypes.h"
#include "PendragonCharacterComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MEDIEVALKNIGHT_API UPendragonCharacterComponent : public UActorComponent
{
    GENERATED_BODY()

public:    
    UPendragonCharacterComponent();

protected:
    virtual void BeginPlay() override;

public:
    // Identity & Lignage
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
    FText CharacterName = FText::FromString(TEXT("Sire Geoffroy"));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
    FText HomeCulture = FText::FromString(TEXT("Française"));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
    FText Religion = FText::FromString(TEXT("Chrétienne"));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
    int32 BirthYear = 1312; // Guerre de Cent Ans (ex: 1337+)

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
    int32 Glory = 1000; // Gloire initiale d'un chevalier bachelier

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
    TArray<FPendragonFamilyLink> FamilyLinks;
    
    // Primary Attributes
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Attributes")
    FPendragonAttributes Attributes;

    // Liste des 13 paires de traits (Chaste/Lustful, Energetic/Lazy, etc.)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Traits")
    TArray<FPendragonTraitPair> Traits;

    // Liste des Passions du chevalier
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Passions")
    TArray<FPendragonPassion> Passions;

    // Dictionnaire enrichi des Compétences
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Skills")
    TMap<FName, FPendragonSkillData> CharacterSkills;

    // --- Helpers & Logic ---
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Traits")
    int32 GetKnockdown () const { return Attributes.GetKnockdown(); }

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Traits")
    int32 GetDamageDice() const { return Attributes.GetDamageBonus(); }

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Traits")
    int32 GetBrawlingDamage() const { return Attributes.GetBrawlingDamage(); }

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Traits")
    int32 GetMovementRate() const { return Attributes.GetMovementRate(); }

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Traits")
    int32 GetMajorWoundThreshold() const { return Attributes.GetMajorWoundThreshold(); }

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Traits")
    int32 GetHealRate() const { return Attributes.GetHealRate(); }

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Traits")
    int32 GetMaxHealth() const { return Attributes.GetMaxHealth(); }

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Traits")
    int32 GetUnconscious() const { return Attributes.GetUnconscious(); }

    // Get the value of a trait (Primary or Opposed)
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Traits")
    int32 GetTraitValue(EPendragonTrait TraitPair, bool bGetPrimary) const;

    // Set the value of a primary trait (automatically clamps between 0 and 20)
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Traits")
    void SetTraitValue(EPendragonTrait TraitPair, int32 NewValue);

    // Perform a standard D20 Pendragon roll against a target skill/trait value
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Mechanics")
    static EPendragonCheckResult PerformD20Check(int32 TargetValue, int32& OutRoll);

    // Helper to perform a check against a specific trait
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Mechanics")
    EPendragonCheckResult CheckTrait(EPendragonTrait TraitPair, bool bCheckPrimary, int32& OutRoll) const;

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Passions")
    void AddOrUpdatePassion(EPendragonPassionType Type, const FString& Target, int32 Value);

    UFUNCTION(BlueprintPure, Category = "Pendragon|Passions")
    int32 GetPassionValue(EPendragonPassionType Type, const FString& Target) const;

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Skills")
    void SetSkillValue(FName SkillID, int32 Value);

    UFUNCTION(BlueprintPure, Category = "Pendragon|Skills")
    int32 GetSkillValue(FName SkillID) const;

    // Coche une case d'expérience suite à un succès
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Progression")
    void CheckSkillForImprovement(FName SkillID);

    // Coche la case d'expérience d'un trait (principal ou opposé)
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Progression")
    void CheckTraitForImprovement(EPendragonTrait Trait, bool bIsPrimaryTrait);

    // Coche la case d'expérience d'une passion
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Progression")
    void CheckPassionForImprovement(EPendragonPassionType Type, const FString& Target);

    // Coche la case d'expérience d'un attribut
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Progression")
    void CheckAttributeForImprovement(EPendragonAttribute Attribute);

    /** Arrondit une division au plus proche (0,5 et plus -> supérieur). Ex: 27/6 = 4.5 -> 5 */
    UFUNCTION(BlueprintPure, Category = "Pendragon|Math")
    static FORCEINLINE int32 RoundDivide(int32 Dividend, int32 Divisor)
    {
        if (Divisor == 0) return 0;
        return FMath::RoundToInt(static_cast<float>(Dividend) / static_cast<float>(Divisor));
    }
};