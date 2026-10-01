// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BlazonEnums.h"
#include "BlazonTypes.generated.h"

USTRUCT(BlueprintType)
struct FCharge
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Charge")
	EBlasonChargeType ChargeType = EBlasonChargeType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Charge", meta = (EditCondition = "ChargeType == EBlasonChargeType::Inanimate", EditConditionHides))
	int32 ChargesNumber = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Charge")
	float ChargeSize = 1.1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Charge", meta = (EditCondition = "ChargeType != EBlasonChargeType::None", EditConditionHides))
	EBlasonColor ChargeTincture = EBlasonColor::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Charge", meta = (EditCondition = "ChargesNumber > 1", EditConditionHides))
	EBlasonArrangement Arrangement = EBlasonArrangement::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Charge", meta = (EditCondition = "ChargesNumber > 0", EditConditionHides))
	EBlasonOrientation Orientation = EBlasonOrientation::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Charge", meta = (EditCondition = "ChargeType == EBlasonChargeType::Ordinary", EditConditionHides))
	EBlasonOrdinaryCharge OrdinaryCharge = EBlasonOrdinaryCharge::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Charge", meta = (EditCondition = "ChargeType == EBlasonChargeType::Animate", EditConditionHides))
	EBlasonAnimateCharge AnimateCharge = EBlasonAnimateCharge::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Charge", meta = (EditCondition = "ChargeType == EBlasonChargeType::Inanimate", EditConditionHides))
	EBlasonInanimateCharge InanimateCharge = EBlasonInanimateCharge::None;
};

USTRUCT(BlueprintType)
struct FBlasonField
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Field")
	EBlasonPattern Pattern = EBlasonPattern::Plain;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Field")
	EBlasonColor FirstColor = EBlasonColor::Azure;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Field", meta = (EditCondition = "Pattern != EBlasonPatterns::Plain", EditConditionHides))
	float PatternMultiplier = 6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Field", meta = (EditCondition = "Pattern != EBlasonPatterns::Plain", EditConditionHides))
	EBlasonColor SecondColor = EBlasonColor::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Charge")
	FCharge Charge;
};

USTRUCT(BlueprintType)
struct FBlasonBorder
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Border")
	bool bBorder = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Border")
	EBlasonPattern Pattern = EBlasonPattern::Plain;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Border")
	EBlasonColor FirstColor = EBlasonColor::Azure;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Border", meta = (EditCondition = "Pattern != EBlasonPatterns::Plain", EditConditionHides))
	float PatternMultiplier = 1.08;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Border", meta = (EditCondition = "Pattern != EBlasonPatterns::Plain", EditConditionHides))
	EBlasonColor SecondColor = EBlasonColor::None;
};

USTRUCT(BlueprintType)
struct FBlasonSimpleDivision
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Division")
	EBlasonDivision Division = EBlasonDivision::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Division")
	FBlasonField FirstPart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Division", meta = (EditCondition = "Division != EBlasonDivision::None", EditConditionHides))
	FBlasonField SecondPart;
};

USTRUCT(BlueprintType)
struct FBlasonComplexDivision
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Division")
	EBlasonDivision Division = EBlasonDivision::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Division")
	FBlasonSimpleDivision FirstPart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blason|Division", meta = (EditCondition = "Division != EBlasonDivision::None", EditConditionHides))
	FBlasonSimpleDivision SecondPart;
};

USTRUCT(BlueprintType)
struct FCoatOfArms
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CoatOfArms")
	FName HouseID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CoatOfArms")
	FName HouseHeadID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CoatOfArms")
	FText HouseMotto = FText::GetEmpty();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CoatOfArms")
	FText HouseDescription = FText::GetEmpty();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CoatOfArms")
	FBlasonBorder Border;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CoatOfArms")
	FBlasonSimpleDivision Content;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CoatOfArms")
	FCharge Charge;
};