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
    // Primary Attributes
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Attributes")
    FPendragonAttributes Attributes;

    // Traits map (Stores value for the primary trait of each pair, secondary is 20 - value)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Traits")
    TMap<EPendragonTrait, int32> Traits;

    // Liste des Passions du chevalier
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Passions")
    TArray<FPendragonPassion> Passions;

    // Dictionnaire enrichi des Compétences
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Skills")
    TMap<FName, FPendragonSkillData> CharacterSkills;

    // --- Helpers & Logic ---

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

    UFUNCTION(BlueprintCallable, Category = "Pendragon|Progression")
    void CheckPassionForImprovement(EPendragonPassionType Type, const FString& Target);
};