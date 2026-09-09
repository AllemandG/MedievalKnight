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

    // Passions array
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Passions")
    TArray<FPendragonPassion> Passions;

    // Skills map (Skill Name -> Value)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Skills")
    TMap<FName, int32> Skills;

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
};