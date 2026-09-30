#pragma once

#include "CoreMinimal.h"
#include "DomainEnums.h"
#include "DomainTypes.h"
#include "Core/MedievalKnightCharacter.h"
#include "UObject/Object.h"
#include "Holding.generated.h"

UCLASS()
class MEDIEVALKNIGHT_API UHolding : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Holding")
	EDomainType DomainType = EDomainType::Manor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Holding")
	ETitle HoldingTitle = ETitle::Knight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Holding")
	AMedievalKnightCharacter* Lord;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Holding")
	FManor CaputMajor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Holding", meta = (EditCondition = "DomainType != EDomainType::None && DomainType != EDomainType::Manor", EditConditionHides))
	TArray<UHolding*> DemesneHoldings;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Holding", meta = (EditCondition = "DomainType != EDomainType::None && DomainType != EDomainType::Manor", EditConditionHides))
	TArray<UHolding*> VassalsHoldings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Holding")
	TArray<UHolding*> NeighbouringHoldings;

	int32 GetDemesneAssizedRent();
	int32 GetTotalAssizedRent();
	static int32 GetManorInvestmentPrivyFunds(FManor Manor);
	static int32 GetManorPrivyFunds(FManor Manor);
	int32 GetDemesnePrivyFunds();
};
