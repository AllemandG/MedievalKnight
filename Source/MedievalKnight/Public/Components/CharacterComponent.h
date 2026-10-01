#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Core/Blason.h"
#include "Core/BlazonTypes.h"
#include "Core/MedievalKnightTypes.h"
#include "MedievalKnight/Public/Core/MedievalKnightEnums.h"
#include "CharacterComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MEDIEVALKNIGHT_API UCharacterComponent : public UActorComponent
{
    GENERATED_BODY()

public:    
    UCharacterComponent();

protected:
    virtual void BeginPlay() override;

public:
    // Identité séparée
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    FText FirstName = FText::FromString(TEXT("Godefroy"));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    FText LastName = FText::FromString(TEXT("de Montmirail"));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    EGender Gender = EGender::Male;

    // Origin : Culture, Religion, Birth Year, Noble, Heir, Hair, Eye, Distinctive Features
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    FCharacterOrigin Origin;

    // Historique Familial
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    FParentHistory ParentHistory;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    int32 Glory = 1000; // Gloire initiale d'un chevalier bachelier

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    UBlason* CoatOfArms;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Identity")
    TArray<FFamilyLink> FamilyLinks;
    
    // Primary Attributes
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    FAttributes Attributes;

    // Liste des 13 paires de traits (Chaste/Lustful, Energetic/Lazy, etc.)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Traits")
    TArray<FTraitPair> Traits;

    // Liste des Passions du chevalier
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Passions")
    TArray<FPassion> Passions;

    // Dictionnaire enrichi des Compétences
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Skills")
    TMap<FName, FSkillData> CharacterSkills;

    // --- Helpers & Logic ---
    UFUNCTION(BlueprintCallable, Category = "Traits")
    int32 GetKnockdown () const { return Attributes.GetKnockdown(); }

    UFUNCTION(BlueprintCallable, Category = "Traits")
    int32 GetDamageDice() const { return Attributes.GetDamageBonus(); }

    UFUNCTION(BlueprintCallable, Category = "Traits")
    int32 GetBrawlingDamage() const { return Attributes.GetBrawlingDamage(); }

    UFUNCTION(BlueprintCallable, Category = "Traits")
    int32 GetMovementRate() const { return Attributes.GetMovementRate(); }

    UFUNCTION(BlueprintCallable, Category = "Traits")
    int32 GetMajorWoundThreshold() const { return Attributes.GetMajorWoundThreshold(); }

    UFUNCTION(BlueprintCallable, Category = "Traits")
    int32 GetHealRate() const { return Attributes.GetHealRate(); }

    UFUNCTION(BlueprintCallable, Category = "Traits")
    int32 GetMaxHealth() const { return Attributes.GetMaxHealth(); }

    UFUNCTION(BlueprintCallable, Category = "Traits")
    int32 GetUnconscious() const { return Attributes.GetUnconscious(); }

    // Get the value of a trait (Primary or Opposed)
    UFUNCTION(BlueprintCallable, Category = "Traits")
    int32 GetTraitValue(ETrait TraitPair, bool bGetPrimary) const;

    // Set the value of a primary trait (automatically clamps between 0 and 20)
    UFUNCTION(BlueprintCallable, Category = "Traits")
    void SetTraitValue(ETrait TraitPair, int32 NewValue);

    // Perform a standard D20 Pendragon roll against a target skill/trait value
    UFUNCTION(BlueprintCallable, Category = "Mechanics")
    static EDiceCheckResult PerformD20Check(int32 TargetValue, int32& OutRoll);

    // Helper to perform a check against a specific trait
    UFUNCTION(BlueprintCallable, Category = "Mechanics")
    EDiceCheckResult CheckTrait(ETrait TraitPair, bool bCheckPrimary, int32& OutRoll) const;

    UFUNCTION(BlueprintCallable, Category = "Passions")
    void AddOrUpdatePassion(EPassionType Type, const FString& Target, int32 Value);

    UFUNCTION(BlueprintPure, Category = "Passions")
    int32 GetPassionValue(EPassionType Type, const FString& Target) const;

    UFUNCTION(BlueprintCallable, Category = "Skills")
    void SetSkillValue(FName SkillID, int32 Value);

    UFUNCTION(BlueprintPure, Category = "Skills")
    int32 GetSkillValue(FName SkillID) const;

    // Coche une case d'expérience suite à un succès
    UFUNCTION(BlueprintCallable, Category = "Progression")
    void CheckSkillForImprovement(FName SkillID);

    // Coche la case d'expérience d'un trait (principal ou opposé)
    UFUNCTION(BlueprintCallable, Category = "Progression")
    void CheckTraitForImprovement(ETrait Trait, bool bIsPrimaryTrait);

    // Coche la case d'expérience d'une passion
    UFUNCTION(BlueprintCallable, Category = "Progression")
    void CheckPassionForImprovement(EPassionType Type, const FString& Target);

    // Coche la case d'expérience d'un attribut
    UFUNCTION(BlueprintCallable, Category = "Progression")
    void CheckAttributeForImprovement(EAttribute Attribute);

    /** Arrondit une division au plus proche (0,5 et plus -> supérieur). Ex: 27/6 = 4.5 -> 5 */
    UFUNCTION(BlueprintPure, Category = "Math")
    static FORCEINLINE int32 RoundDivide(int32 Dividend, int32 Divisor)
    {
        if (Divisor == 0) return 0;
        return FMath::RoundToInt(static_cast<float>(Dividend) / static_cast<float>(Divisor));
    }
};