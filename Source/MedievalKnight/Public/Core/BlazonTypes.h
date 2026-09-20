// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlazonEnums.h"
#include "BlazonTypes.generated.h"

USTRUCT(BlueprintType)
struct FCharge
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Charge")
	EBlazonChargeType ChargeType = EBlazonChargeType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Charge", meta = (EditCondition = "ChargeType == EBlazonChargeType::Inanimate", EditConditionHides))
	int32 ChargesNumber = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Charge", meta = (EditCondition = "ChargeType != EBlazonChargeType::None", EditConditionHides))
	EBlazonColor ChargeTincture = EBlazonColor::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Charge", meta = (EditCondition = "ChargesNumber > 1", EditConditionHides))
	EBlazonArrangement Arrangement = EBlazonArrangement::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Charge", meta = (EditCondition = "ChargesNumber > 0", EditConditionHides))
	EBlazonOrientation Orientation = EBlazonOrientation::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Charge", meta = (EditCondition = "ChargeType == EBlazonChargeType::Ordinary", EditConditionHides))
	EBlazonOrdinaryCharge OrdinaryCharge = EBlazonOrdinaryCharge::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Charge", meta = (EditCondition = "ChargeType == EBlazonChargeType::Animate", EditConditionHides))
	EBlazonAnimateCharge AnimateCharge = EBlazonAnimateCharge::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Charge", meta = (EditCondition = "ChargeType == EBlazonChargeType::Inanimate", EditConditionHides))
	EBlazonInanimateCharge InanimateCharge = EBlazonInanimateCharge::None;
};

USTRUCT(BlueprintType)
struct FBlazonField
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Field")
	EBlazonPattern Pattern = EBlazonPattern::Plain;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Field")
	EBlazonColor FirstColor = EBlazonColor::Azure;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Field", meta = (EditCondition = "Pattern != EBlazonPatterns::Plain", EditConditionHides))
	int32 PatternMultiplier = 6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Field", meta = (EditCondition = "Pattern != EBlazonPatterns::Plain", EditConditionHides))
	EBlazonColor SecondColor = EBlazonColor::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Charge")
	FCharge Charge;
};

USTRUCT(BlueprintType)
struct FBlazonBorder
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Border")
	bool bHasBorder = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Border")
	EBlazonPattern Pattern = EBlazonPattern::Plain;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Border")
	EBlazonColor FirstColor = EBlazonColor::Azure;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Border", meta = (EditCondition = "Pattern != EBlazonPatterns::Plain", EditConditionHides))
	int32 PatternMultiplier = 6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Border", meta = (EditCondition = "Pattern != EBlazonPatterns::Plain", EditConditionHides))
	EBlazonColor SecondColor = EBlazonColor::None;
};

USTRUCT(BlueprintType)
struct FBlazonSimpleDivision
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Division")
	EBlazonDivision Division = EBlazonDivision::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Division")
	FBlazonField FirstPart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Division", meta = (EditCondition = "Division != EBlazonDivision::None", EditConditionHides))
	FBlazonField SecondPart;
};

USTRUCT(BlueprintType)
struct FBlazonComplexDivision
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Division")
	EBlazonDivision Division = EBlazonDivision::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Division")
	FBlazonSimpleDivision FirstPart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blazon|Division", meta = (EditCondition = "Division != EBlazonDivision::None", EditConditionHides))
	FBlazonSimpleDivision SecondPart;
};