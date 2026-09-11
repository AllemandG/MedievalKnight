#pragma once

#include "CoreMinimal.h"
#include "PendragonEnums.generated.h"

UENUM(BlueprintType)
enum class EPendragonTrait : uint8
{
	Chaste			UMETA(DisplayName = "Chaste"),
	Lustful			UMETA(DisplayName = "Lubrique"),
	Energetic		UMETA(DisplayName = "Dynamique"),
	Lazy			UMETA(DisplayName = "Fainéant"),
	Forgiving		UMETA(DisplayName = "Indulgent"),
	Vengeful		UMETA(DisplayName = "Vengeur"),
	Generous 		UMETA(DisplayName = "Généreux"),
	Selfish			UMETA(DisplayName = "Égoïste"),
	Honest 			UMETA(DisplayName = "Honnête"),
	Deceitful		UMETA(DisplayName = "Fourbe"),
	Just 			UMETA(DisplayName = "Juste"),
	Arbitrary		UMETA(DisplayName = "Arbitraire"),
	Merciful		UMETA(DisplayName = "Clément"),
	Cruel			UMETA(DisplayName = "Cruel"),
	Modest 			UMETA(DisplayName = "Modeste"),
	Proud			UMETA(DisplayName = "Fier"),
	Prudent 		UMETA(DisplayName = "Prudent"),
	Reckless		UMETA(DisplayName = "Téméraire"),
	Spiritual		UMETA(DisplayName = "Spirituel"),
	Worldly			UMETA(DisplayName = "Mondain"),
	Temperate		UMETA(DisplayName = "Tempéré"),
	Indulgent		UMETA(DisplayName = "Laxiste"),
	Trusting		UMETA(DisplayName = "Confiant"),
	Suspicious		UMETA(DisplayName = "Méfiant"),
	Valorous		UMETA(DisplayName = "Valeureux"),
	Cowardly		UMETA(DisplayName = "Lâche")
};

UENUM(BlueprintType)
enum class EPendragonCheckResult : uint8
{
	CriticalSuccess UMETA(DisplayName = "Critical Success"),
	Success         UMETA(DisplayName = "Success"),
	Failure         UMETA(DisplayName = "Failure"),
	Fumble          UMETA(DisplayName = "Fumble")
};

UENUM(BlueprintType)
enum class EPendragonAttribute : uint8
{
	Size,
	Dexterity,
	Strength,
	Constitution,
	Appearance
};