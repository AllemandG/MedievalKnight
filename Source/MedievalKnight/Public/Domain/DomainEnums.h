#pragma once

#include "CoreMinimal.h"
#include "DomainEnums.generated.h"

UENUM(BlueprintType)
enum class EDomainType : uint8
{
	None		UMETA(DisplayName = "None"),
	Manor		UMETA(DisplayName = "Manor"),
	ManorGroup	UMETA(DisplayName = "Manor Group"),
	Barony		UMETA(DisplayName = "Barony"),
	County		UMETA(DisplayName = "County"),
	Duchy		UMETA(DisplayName = "Duchy"),
	Kingdom		UMETA(DisplayName = "Kingdom")
};

UENUM(BlueprintType)
enum class ETitle : uint8
{
	None		UMETA(DisplayName = "None"),
	Page 		UMETA(DisplayName = "Page "),
	Squire 		UMETA(DisplayName = "Squire"),
	Esquire 	UMETA(DisplayName = "Esquire"),
	Sir			UMETA(DisplayName = "Sir"),
	Knight		UMETA(DisplayName = "Knight"),
	Lord		UMETA(DisplayName = "Lord"),
	Banneret	UMETA(DisplayName = "Banneret"),
	Baron 		UMETA(DisplayName = "Baron"),
	Count		UMETA(DisplayName = "Count"),
	Duke 		UMETA(DisplayName = "Duke"),
	King 		UMETA(DisplayName = "King")
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
	Stream 				UMETA(DisplayName = "Stream"),
	River 				UMETA(DisplayName = "River"),
	TownManse 			UMETA(DisplayName = "Town Manse"),
	CityTownhouse 		UMETA(DisplayName = "City Townhouse"),
	CapitalTownhouse 	UMETA(DisplayName = "Capital Townhouse")
};

UENUM(BlueprintType)
enum class EManorImprovementType : uint8
{
	None					UMETA(DisplayName = "None"),
	Courtyard				UMETA(DisplayName = "Courtyard"),
	WallFresco				UMETA(DisplayName = "Wall Fresco"),
	DecorativeFlourishes	UMETA(DisplayName = "Decorative Flourishes"),
	TileRoof				UMETA(DisplayName = "Tile Roof"),
	LeadRoof				UMETA(DisplayName = "Lead Roof"),
	Mosaic 					UMETA(DisplayName = "Mosaic"),
	FireplaceAndChimney		UMETA(DisplayName = "Fireplace and Chimney"),
	Baths 					UMETA(DisplayName = "Baths"),
	GlassWindows 			UMETA(DisplayName = "Glass Windows"),
	TileFloors 				UMETA(DisplayName = "Tile Floors"),
	StainedGlass 			UMETA(DisplayName = "Stained Glass"),
	Wainscoting 			UMETA(DisplayName = "Wainscoting"),
	SecretEscapeTunnel		UMETA(DisplayName = "Secret Escape Tunnel"),
	StoneHall 				UMETA(DisplayName = "Stone Hall"),
	LargeWoodenHall			UMETA(DisplayName = "Large Wooden Hall"),
	LargeStoneHall			UMETA(DisplayName = "Large Stone Hall"),
	GreatHall				UMETA(DisplayName = "Great Hall")
};

UENUM(BlueprintType)
enum class EManorInvestmentType : uint8
{
	None				UMETA(DisplayName = "None"),
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
	None				UMETA(DisplayName = "None"),
	Almshouse			UMETA(DisplayName = "Almshouse"),
	Chapel				UMETA(DisplayName = "Chapel"),
	Fountain			UMETA(DisplayName = "Fountain"),
	GazeboOrBower 		UMETA(DisplayName = "Gazebo or Bower"),
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
	StatelyManor		UMETA(DisplayName = "Stately Manor"),
};

UENUM(BlueprintType)
enum class EFortificationType : uint8
{
	None				UMETA(DisplayName = "None"),
	Ditch 				UMETA(DisplayName = "Ditch"),
	DitchAndRempart 	UMETA(DisplayName = "Ditch and Rempart"),
	MoatAndRempart 		UMETA(DisplayName = "Moat and Rempart"),
	Palisade 			UMETA(DisplayName = "Palisade"),
	Gate 				UMETA(DisplayName = "Gate"),
	GateWorks 			UMETA(DisplayName = "Gate Works"),
	PosternGate 		UMETA(DisplayName = "Postern Gate"),
	Motte 				UMETA(DisplayName = "Motte"),
	WoodenTower 		UMETA(DisplayName = "Wooden Tower"),
	RockWall 			UMETA(DisplayName = "Rock Wall"),
	StoneTower 			UMETA(DisplayName = "Stone Tower")
};

UENUM(BlueprintType)
enum class EBuildingType : uint8
{
	None				UMETA(DisplayName = "None"),
	ManorHall 			UMETA(DisplayName = "Manor Hall"),
	Fortification 		UMETA(DisplayName = "Fortification"),
	Stables				UMETA(DisplayName = "Stables"),
	LargeStables 		UMETA(DisplayName = "Large Stables"),
	Housing				UMETA(DisplayName = "Housing"),
	Mill 				UMETA(DisplayName = "Mill"),
	Bakery				UMETA(DisplayName = "Bakery"),
	Smithy				UMETA(DisplayName = "Smithy"),
	Forge 				UMETA(DisplayName = "Forge "),
	LargeForge 			UMETA(DisplayName = "Large Forge"),
	Well 				UMETA(DisplayName = "Well"),
	CarpenterAndJoinery UMETA(DisplayName = "Carpenter & Joinery"),
	Cooper 				UMETA(DisplayName = "Cooper"),
	Pottery 			UMETA(DisplayName = "Pottery"),
	Tailor 				UMETA(DisplayName = "Tailor"),
	Artisan 			UMETA(DisplayName = "Artisan"),
	Jeweler 			UMETA(DisplayName = "Jeweler"),
	HuntingLodge 		UMETA(DisplayName = "Hunting Lodge"),
	Scriptorium 		UMETA(DisplayName = "Scriptorium"),
	Church				UMETA(DisplayName = "Church"),
	ParishChurch		UMETA(DisplayName = "Parish Church"),
	Barn 				UMETA(DisplayName = "Barn"),
	Granaries 			UMETA(DisplayName = "Granaries"),
	Guardhouse 			UMETA(DisplayName = "Guardhouse"),
	Tannery 			UMETA(DisplayName = "Tannery"),
	Brewery 			UMETA(DisplayName = "Brewery"),
	Winery 				UMETA(DisplayName = "Winery"),
	Vineyard 			UMETA(DisplayName = "Vineyard"),
	AdditionalHousing	UMETA(DisplayName = "Additional Housing"),
	IrrigationDitches	UMETA(DisplayName = "Irrigation Ditches"),
	SheepHerd			UMETA(DisplayName = "Sheep Herd"),
	Vacary 				UMETA(DisplayName = "Vacary"),
	ClearingOfForests 	UMETA(DisplayName = "Clearing of Forests"),
	IronMine 			UMETA(DisplayName = "Iron Mine"),
	Armory				UMETA(DisplayName = "Armory"),
	Chace 				UMETA(DisplayName = "Chace"),
	Fishery 			UMETA(DisplayName = "Fishery"),
	Market 				UMETA(DisplayName = "Market"),
	MarketHall			UMETA(DisplayName = "Market Hall"),
	Orchard 			UMETA(DisplayName = "Orchard"),
	SalvageRights 		UMETA(DisplayName = "Salvage Rights"),
	Bridge 				UMETA(DisplayName = "Bridge"),
	RoadTolls 			UMETA(DisplayName = "Road Tolls"),
	Salthouse 			UMETA(DisplayName = "Salthouse "),
	RiverTolls 			UMETA(DisplayName = "River Tolls"),
	DeerPark 			UMETA(DisplayName = "Deer Park"),
	Coneygarth 			UMETA(DisplayName = "Coneygarth"),
	Apiary				UMETA(DisplayName = "Apiary"),
	StudFarm 			UMETA(DisplayName = "Stud Farm")
};

UENUM(BlueprintType)
enum class EProfession : uint8
{
	None				UMETA(DisplayName = "None"),
	Housekeeper			UMETA(DisplayName = "Housekeeper"),
	Maid                UMETA(DisplayName = "Maid"),
	Lackey				UMETA(DisplayName = "Lackey"),
	Cook				UMETA(DisplayName = "Cook"),
	Scullion 			UMETA(DisplayName = "Scullion"),
	StableMaster 		UMETA(DisplayName = "Stable Master"),
	StableBoy 			UMETA(DisplayName = "Stable Boy"),
	Chaplain 			UMETA(DisplayName = "Chaplain"),
	Chef 				UMETA(DisplayName = "Chef"),
	Falconer  			UMETA(DisplayName = "Falconer"),
	Huntsman 			UMETA(DisplayName = "Huntsman"),
	MasterOfHounds 		UMETA(DisplayName = "Master of Hounds"),
	Majordomo 			UMETA(DisplayName = "Majordomo"),
	Groom 				UMETA(DisplayName = "Groom"),
	Steward 			UMETA(DisplayName = "Steward"),
	Tailor 				UMETA(DisplayName = "Tailor"),
	Valet 				UMETA(DisplayName = "Valet"),
	LadyDresser 		UMETA(DisplayName = "Lady's Dresser"),
	Wisewoman 			UMETA(DisplayName = "Wisewoman"),
	Clerk 				UMETA(DisplayName = "Clerk"),
	Engineer 			UMETA(DisplayName = "Engineer"),
	Lawyer 				UMETA(DisplayName = "Lawyer"),
	Physician 			UMETA(DisplayName = "Physician"),
	Castellan 			UMETA(DisplayName = "Castellan"),
	Constable 			UMETA(DisplayName = "Constable"),
	Dapifer 			UMETA(DisplayName = "Dapifer"),
	Marshall 			UMETA(DisplayName = "Marshall"),
	Pincerna 			UMETA(DisplayName = "Pincerna"),
	Seneschal 			UMETA(DisplayName = "Seneschal")
};

UENUM(BlueprintType)
enum class ESoldierType : uint8
{
	GarrisonSoldier		UMETA(DisplayName = "Garrison Soldier"),
	Crossbowman			UMETA(DisplayName = "Crossbowman"),
	Spearman			UMETA(DisplayName = "Spearman"),
	Sergeant			UMETA(DisplayName = "Sergeant"),
	MountedSergeant		UMETA(DisplayName = "Mounted Sergeant"),
	Knight				UMETA(DisplayName = "Knight"),
};