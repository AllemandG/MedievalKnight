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
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
    FText FirstName = FText::FromString(TEXT("Geoffroy"));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
    FText LastName = FText::FromString(TEXT("de Charny"));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
    EGender Gender = EGender::Male;

    // Héraldique & Apparence
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
    FHeraldry Heraldry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
    FAppearanceDetails Appearance;

    // Historique Familial
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
    FParentHistory ParentHistory;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
    FText HomeCulture = FText::FromString(TEXT("French"));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
    FText Religion = FText::FromString(TEXT("Christian"));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
    int32 BirthYear = 1312; // Guerre de Cent Ans (ex: 1337+)

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
    int32 Glory = 1000; // Gloire initiale d'un chevalier bachelier

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
    UBlason* CoatOfArms;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Identity")
    TArray<FFamilyLink> FamilyLinks;
    
    // Primary Attributes
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Attributes")
    FAttributes Attributes;

    // Liste des 13 paires de traits (Chaste/Lustful, Energetic/Lazy, etc.)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Traits")
    TArray<FTraitPair> Traits;

    // Liste des Passions du chevalier
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Passions")
    TArray<FPassion> Passions;

    // Dictionnaire enrichi des Compétences
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Skills")
    TMap<FName, FSkillData> CharacterSkills;

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
    int32 GetTraitValue(ETrait TraitPair, bool bGetPrimary) const;

    // Set the value of a primary trait (automatically clamps between 0 and 20)
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Traits")
    void SetTraitValue(ETrait TraitPair, int32 NewValue);

    // Perform a standard D20 Pendragon roll against a target skill/trait value
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Mechanics")
    static EDiceCheckResult PerformD20Check(int32 TargetValue, int32& OutRoll);

    // Helper to perform a check against a specific trait
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Mechanics")
    EDiceCheckResult CheckTrait(ETrait TraitPair, bool bCheckPrimary, int32& OutRoll) const;

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Passions")
    void AddOrUpdatePassion(EPassionType Type, const FString& Target, int32 Value);

    UFUNCTION(BlueprintPure, Category = "Pendragon|Passions")
    int32 GetPassionValue(EPassionType Type, const FString& Target) const;

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Skills")
    void SetSkillValue(FName SkillID, int32 Value);

    UFUNCTION(BlueprintPure, Category = "Pendragon|Skills")
    int32 GetSkillValue(FName SkillID) const;

    // Coche une case d'expérience suite à un succès
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Progression")
    void CheckSkillForImprovement(FName SkillID);

    // Coche la case d'expérience d'un trait (principal ou opposé)
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Progression")
    void CheckTraitForImprovement(ETrait Trait, bool bIsPrimaryTrait);

    // Coche la case d'expérience d'une passion
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Progression")
    void CheckPassionForImprovement(EPassionType Type, const FString& Target);

    // Coche la case d'expérience d'un attribut
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Progression")
    void CheckAttributeForImprovement(EAttribute Attribute);

    /** Arrondit une division au plus proche (0,5 et plus -> supérieur). Ex: 27/6 = 4.5 -> 5 */
    UFUNCTION(BlueprintPure, Category = "Pendragon|Math")
    static FORCEINLINE int32 RoundDivide(int32 Dividend, int32 Divisor)
    {
        if (Divisor == 0) return 0;
        return FMath::RoundToInt(static_cast<float>(Dividend) / static_cast<float>(Divisor));
    }
};