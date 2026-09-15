#pragma once

#include "CoreMinimal.h"
#include "DomainEnums.h"
#include "Combat/PendragonNPCData.h"
#include "DomainTypes.generated.h"

USTRUCT(BlueprintType)
struct FBuilding
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
	EBuildingType BuildingType = EBuildingType::ManorHall;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
	int32 MoneyIncome = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
	int32 GloryIncome = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
	int32 BuildingCost = 10;

	// Building time in months
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
	int32 BuildingTime = 12;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
	int32 MaintenanceCost = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
	int32 DefensiveValue = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building|Fortification", meta = (EditCondition = "BuildingType == EBuildingType::Fortification", EditConditionHides))
	EFortificationType FortificationType = EFortificationType::None;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building|Manor", meta = (EditCondition = "BuildingType == EBuildingType::ManorHall", EditConditionHides))
	EManorHallType ManorHall = EManorHallType::SimpleWoodenHall;
};

USTRUCT(BlueprintType)
struct FSettlement
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settlement")
	ESettlementType SettlementType = ESettlementType::Village;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settlement")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settlement")
	int32 AssizedRent = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settlement")
	int32 Population = 500;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settlement")
	TArray<FBuilding> Buildings;
};

USTRUCT(BlueprintType)
struct FManor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manor")
	EManorType ManorType = EManorType::Manor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manor")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manor", meta = (EditCondition = "ManorType != EManorType::None", EditConditionHides))
	FBuilding ManorHall;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manor")
	int32 AssizedRent = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manor")
	int32 BaseGlory = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manor")
	int32 BaseMaintenance = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manor")
	int32 BasePrivyFundsIncome = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manor")
	int32 CommonersPopulation = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manor")
	FSettlement Settlement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manor")
	TArray<FBuilding> Buildings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manor")
	TArray<EManorNotableFeature> Features;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manor", meta = (EditCondition = "ManorType != EManorType::None", EditConditionHides))
	TArray<EManorImprovementType> Improvements;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manor")
	TArray<EManorInvestmentType> Investments;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manor", meta = (EditCondition = "ManorType != EManorType::None", EditConditionHides))
	TArray<EManorEnhancementType> Enhancements;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manor|Retinue", meta = (EditCondition = "ManorType != EManorType::None", EditConditionHides))
	TMap<ESoldierType, int32> Retinue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manor|Personnel", meta = (EditCondition = "ManorType != EManorType::None", EditConditionHides))
	TMap<EProfession, FPendragonNPC> Personnel;
};