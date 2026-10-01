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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason")
	FName HouseID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason")
	FName HouseHeadID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason")
	FText HouseMotto;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason")
	FText HouseDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason")
	FBlasonBorder Border;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason")
	FBlasonSimpleDivision Content;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason")
	FCharge Charge;
};