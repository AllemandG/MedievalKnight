#pragma once

#include "CoreMinimal.h"
#include "BlazonTypes.h"
#include "UObject/Object.h"
#include "Blazon.generated.h"

UCLASS()
class MEDIEVALKNIGHT_API UBlazonDivision : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Division")
	bool bIsComplex = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Division")
	EBlazonDivision Division = EBlazonDivision::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Division", meta = (EditCondition = "bIsComplex == false", EditConditionHides))
	FBlazonField FirstField;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Division", meta = (EditCondition = "bIsComplex == false && Division != EBlazonDivision::None", EditConditionHides))
	FBlazonField SecondField;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Division", meta = (EditCondition = "bIsComplex == true", EditConditionHides))
	UBlazonDivision* FirstPart = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Division", meta = (EditCondition = "bIsComplex == true", EditConditionHides))
	UBlazonDivision* SecondPart = nullptr;
};

UCLASS()
class MEDIEVALKNIGHT_API UBasicBlazon : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Field")
	EBlazonPattern Pattern = EBlazonPattern::Plain;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Field")
	EBlazonColor FirstColor = EBlazonColor::Azure;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Field", meta = (EditCondition = "Pattern != EBlazonPatterns::Plain", EditConditionHides))
	int32 PatternMultiplier = 6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Field", meta = (EditCondition = "Pattern != EBlazonPatterns::Plain", EditConditionHides))
	EBlazonColor SecondColor = EBlazonColor::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Charge")
	EBlazonChargeType ChargeType = EBlazonChargeType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Charge", meta = (EditCondition = "ChargeType != EBlazonChargeType::None", EditConditionHides))
	EBlazonColor ChargeTincture = EBlazonColor::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Charge", meta = (EditCondition = "ChargeType == EBlazonChargeType::Animate", EditConditionHides))
	EBlazonAnimateCharge AnimateCharge = EBlazonAnimateCharge::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Charge", meta = (EditCondition = "ChargeType == EBlazonChargeType::Inanimate", EditConditionHides))
	EBlazonInanimateCharge InanimateCharge = EBlazonInanimateCharge::None;
};

UCLASS()
class MEDIEVALKNIGHT_API UBlazon : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Border", meta = (EditCondition = "bHasBorder == true"))
	FBlazonBorder Border;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon")
	UBlazonDivision* Content;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon")
	FCharge Charge;
};