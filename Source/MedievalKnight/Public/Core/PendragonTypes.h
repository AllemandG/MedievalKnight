#pragma once

#include "CoreMinimal.h"
#include "PendragonTypes.generated.h"

USTRUCT(BlueprintType)
struct FPendragonAttributes
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int32 Size = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int32 Strength = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int32 Dexterity = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int32 Constitution = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int32 Appearance = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes|State")
	int32 CurrentHealth = 20;

	// Derived Statistics (Getters)
	int32 GetMaxHealth() const
	{
		return Size + Constitution;
	}

	int32 GetMajorWoundThreshold() const
	{
		return Constitution;
	}

	int32 GetHealRate() const
	{
		return FMath::Max(1, Constitution / 5);
	}

	int32 GetDamageBonus() const
	{
		return (Strength + Size) / 6;
	}
};

USTRUCT(BlueprintType)
struct FPendragonPassion
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Passion")
	FName PassionName = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Passion", meta = (ClampMin = 0, ClampMax = 20))
	int32 Value = 6;
};