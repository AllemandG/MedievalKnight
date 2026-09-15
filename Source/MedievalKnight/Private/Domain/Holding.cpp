// Fill out your copyright notice in the Description page of Project Settings.


#include "Domain/Holding.h"


int32 UHolding::GetDemesneAssizedRent()
{
	int32 total = 0;

	total += CaputMajor.AssizedRent + CaputMajor.Settlement.AssizedRent;
	
	for (UHolding* holding : DemesneHoldings)
	{
		total += holding->GetDemesneAssizedRent();
	}
	
	return total;
}

int32 UHolding::GetTotalAssizedRent()
{
	int32 total = 0;

	total += CaputMajor.AssizedRent + CaputMajor.Settlement.AssizedRent;

	for (UHolding* holding : DemesneHoldings)
	{
		total += holding->GetTotalAssizedRent();
	}

	for (UHolding* holding : VassalsHoldings)
	{
		total += holding->GetTotalAssizedRent();
	}

	return total;
}

int32 UHolding::GetManorInvestmentPrivyFunds(FManor Manor)
{
	int32 total = 0;
	for (EManorInvestmentType Investment : Manor.Investments)
	{
		switch (Investment)
		{
		case EManorInvestmentType::AdditionalPeasants:
			if (Manor.Features.Contains(EManorNotableFeature::ClearedWastes)) { total += 2; } else { total += 1; }
			break;
		case EManorInvestmentType::DeerPark:
			if (Manor.Features.Contains(EManorNotableFeature::LushForests)) { total += 2; } else { total += 1; }
			break;
		case EManorInvestmentType::SheepHerd:
			if (Manor.Features.Contains(EManorNotableFeature::RollingDowns)) { total += 2; } else { total += 1; }
			break;
		case EManorInvestmentType::Armory:
			if (Manor.Investments.Contains(EManorInvestmentType::IronMine)) { total += 2; } else { total += 1; }
			break;
		default:
			total +=1;
		}
	}
	return total;
}

int32 UHolding::GetManorPrivyFunds(FManor Manor)
{
	int32 total = 0;
	total += Manor.BasePrivyFundsIncome + GetManorInvestmentPrivyFunds(Manor);
	
	for (FBuilding mBuilding : Manor.Buildings)
	{
		total += mBuilding.MoneyIncome - mBuilding.MaintenanceCost;
	}
	
	for (FBuilding sBuilding : Manor.Settlement.Buildings)
	{
		total += sBuilding.MoneyIncome - sBuilding.MaintenanceCost;
	}

	return total;
}

int32 UHolding::GetDemesnePrivyFunds()
{
	int32 total = 0;
	
	total += GetManorPrivyFunds(CaputMajor);

	for (UHolding* holding : DemesneHoldings)
	{
		total += holding->GetDemesnePrivyFunds();
	}

	return total;
}
