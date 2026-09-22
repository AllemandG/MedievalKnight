#pragma once

#include "CoreMinimal.h"
#include "BlazonTypes.h"
#include "UObject/Object.h"
#include "Blason.generated.h"

UCLASS()
class MEDIEVALKNIGHT_API UBlasonDivision : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Division")
	bool bIsComplex = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Division")
	EBlasonDivision Division = EBlasonDivision::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Division", meta = (EditCondition = "bIsComplex == false", EditConditionHides))
	FBlasonField FirstField;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Division", meta = (EditCondition = "bIsComplex == false && Division != EBlasonDivision::None", EditConditionHides))
	FBlasonField SecondField;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Division", meta = (EditCondition = "bIsComplex == true", EditConditionHides))
	UBlasonDivision* FirstPart = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Division", meta = (EditCondition = "bIsComplex == true", EditConditionHides))
	UBlasonDivision* SecondPart = nullptr;
};

UCLASS()
class MEDIEVALKNIGHT_API UBlason : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Border", meta = (EditCondition = "bHasBorder == true"))
	FBlasonBorder Border;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason")
	FBlasonSimpleDivision Content;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason")
	FCharge Charge;
};