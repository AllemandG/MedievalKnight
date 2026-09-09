#pragma once

#include "CoreMinimal.h"
#include "PendragonEnums.generated.h"

UENUM(BlueprintType)
enum class EPendragonTrait : uint8
{
	Chaste_Lustful       UMETA(DisplayName = "Chaste / Lustful"),
	Energetic_Lazy       UMETA(DisplayName = "Energetic / Lazy"),
	Forgiving_Vengeful   UMETA(DisplayName = "Forgiving / Vengeful"),
	Generous_Selfish     UMETA(DisplayName = "Generous / Selfish"),
	Honest_Deceitful     UMETA(DisplayName = "Honest / Deceitful"),
	Just_Arbitrary       UMETA(DisplayName = "Just / Arbitrary"),
	Merciful_Cruel       UMETA(DisplayName = "Merciful / Cruel"),
	Modest_Proud         UMETA(DisplayName = "Modest / Proud"),
	Pious_Worldly        UMETA(DisplayName = "Pious / Worldly"),
	Prudent_Reckless     UMETA(DisplayName = "Prudent / Reckless"),
	Temperate_Indulgent  UMETA(DisplayName = "Temperate / Indulgent"),
	Trusting_Suspicious  UMETA(DisplayName = "Trusting / Suspicious"),
	Valiant_Cowardly     UMETA(DisplayName = "Valiant / Cowardly")
};

UENUM(BlueprintType)
enum class EPendragonCheckResult : uint8
{
	CriticalSuccess UMETA(DisplayName = "Critical Success"),
	Success         UMETA(DisplayName = "Success"),
	Failure         UMETA(DisplayName = "Failure"),
	Fumble          UMETA(DisplayName = "Fumble")
};