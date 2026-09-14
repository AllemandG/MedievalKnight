#pragma once

#include "CoreMinimal.h"
#include "DomainEnums.generated.h"

UENUM(BlueprintType)
enum class EDomainType : uint8
{
	None UMETA(DisplayName = "None")
};

UENUM(BlueprintType)
enum class EManorType : uint8
{
	None		UMETA(DisplayName = "None"),
	Manor		UMETA(DisplayName = "Manor"),
	Castle		UMETA(DisplayName = "Castle"),
	Palace		UMETA(DisplayName = "Palace")
};

UENUM(BlueprintType)
enum class ESettlementType : uint8
{
	None		UMETA(DisplayName = "None"),
	Hamlet		UMETA(DisplayName = "Hamlet"),
	Village		UMETA(DisplayName = "Village"),
	Town 		UMETA(DisplayName = "Town"),
	LargeTown 	UMETA(DisplayName = "Large Town"),
	City		UMETA(DisplayName = "City")
};

UENUM(BlueprintType)
enum class EManorNotableFeature : uint8
{
	None				UMETA(DisplayName = "None"),
	HauntedWastes		UMETA(DisplayName = "Haunted Wastes"),
	FamousChurch		UMETA(DisplayName = "Famous Church"),
	EternalSpring		UMETA(DisplayName = "Eternal Spring"),
	RomanRuins			UMETA(DisplayName = "Roman Ruins"),
	StandingStones		UMETA(DisplayName = "Standing Stones"),
	Bog					UMETA(DisplayName = "Bog"),
	Barrow 				UMETA(DisplayName = "Barrow"),
	FamousBattleSite	UMETA(DisplayName = "Famous Battle Site"),
	LushForests			UMETA(DisplayName = "Lush Forests"),
	ClearedWastes		UMETA(DisplayName = "Cleared Wastes"),
	RollingDowns		UMETA(DisplayName = "Rolling Downs"),
	AncientOakTree 		UMETA(DisplayName = "Ancent Oak Tree"),
	TownManse 			UMETA(DisplayName = "Town Manse"),
	CityTownhouse 		UMETA(DisplayName = "City Townhouse"),
	CapitalTownhouse 	UMETA(DisplayName = "Capital Townhouse"),
};

UENUM(BlueprintType)
enum class EManorInvestmentType : uint8
{
	AdditionalPeasants	UMETA(DisplayName = "Additional Peasants"),
	IrrigationDitches	UMETA(DisplayName = "Irrigation Ditches"),
	SheepHerd 			UMETA(DisplayName = "Sheep Herd"),
	Vacary 				UMETA(DisplayName = "Vacary"),
	ClearingOfForests 	UMETA(DisplayName = "Clearing of Forests"),
	IronMine 			UMETA(DisplayName = "Iron Mine"),
	Armory				UMETA(DisplayName = "Armory"),
	Chace 				UMETA(DisplayName = "Chace"),
	Fishery 			UMETA(DisplayName = "Fishery"),
	Market 				UMETA(DisplayName = "Market"),
	Orchard 			UMETA(DisplayName = "Orchard"),
	SalvageRights 		UMETA(DisplayName = "Salvage Rights"),
	Bridge 				UMETA(DisplayName = "Bridge"),
	RoadTolls 			UMETA(DisplayName = "Road Tolls"),
	Salthouse 			UMETA(DisplayName = "Salthouse "),
	RiverTolls 			UMETA(DisplayName = "River Tolls"),
	DeerPark 			UMETA(DisplayName = "Deer Park"),
	Coneygarth 			UMETA(DisplayName = "Coneygarth"),
	Apiary				UMETA(DisplayName = "Apiary"),
	HorseHerd 			UMETA(DisplayName = "Horse Herd")
};

UENUM(BlueprintType)
enum class EManorEnhancementType : uint8
{
	Almshouse			UMETA(DisplayName = "Almshouse"),
	Chapel				UMETA(DisplayName = "Chapel"),
	Fountain			UMETA(DisplayName = "Fountain"),
	Bower 				UMETA(DisplayName = "Bower"),
	GuestHouse			UMETA(DisplayName = "Guest House"),
	Hermitage			UMETA(DisplayName = "Hermitage"),
	Hospital			UMETA(DisplayName = "Hospital"),
	JoustingLists 		UMETA(DisplayName = "Jousting Lists"),
	LargeKennel			UMETA(DisplayName = "Large Kennel"),
	Leprosarium			UMETA(DisplayName = "Leprosarium"),
	LargeMews			UMETA(DisplayName = "Large Mews"),
	OrnamentalGarden 	UMETA(DisplayName = "Ornament Garden"),
	Endowment			UMETA(DisplayName = "Endowment"),
	WishingWell 		UMETA(DisplayName = "Wishing Well"),
	OakGrove 			UMETA(DisplayName = "Oak Grove"),
	ChristianMonument	UMETA(DisplayName = "Christian Monument"),
	ConfessionalMural 	UMETA(DisplayName = "Confessional Mural"),
	HedgeMaze 			UMETA(DisplayName = "Hedge Maze"),
	StandingStones		UMETA(DisplayName = "Standing Stones"),
	TortureChamber		UMETA(DisplayName = "Torture Chamber")
};

UENUM(BlueprintType)
enum class EManorHallType : uint8
{
	SimpleWoodenHall	UMETA(DisplayName = "Simple Wooden Hall"),
	LargeWoodenHall 	UMETA(DisplayName = "Large Wooden Hall"),
	StoneHall			UMETA(DisplayName = "Stone Hall"),
	LargeStoneHall		UMETA(DisplayName = "Large Stone Hall"),
	GreatWoodenHall		UMETA(DisplayName = "Great Wooden Hall"),
	ShellKeep 			UMETA(DisplayName = "Shell Keep"),
};

UENUM(BlueprintType)
enum class EVillageBuildingType : uint8
{
	Church	UMETA(DisplayName = "Church"),
	Mill 	UMETA(DisplayName = "Mill"),
};