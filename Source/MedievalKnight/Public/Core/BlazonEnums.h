#pragma once

#include "CoreMinimal.h"
#include "BlazonEnums.generated.h"

UENUM(BlueprintType)
enum class EBlazonColor : uint8
{
	None			UMETA(DisplayName = "None"),
	Argent			UMETA(DisplayName = "Argent"),
	Or				UMETA(DisplayName = "Or"),
	Gules			UMETA(DisplayName = "Gules"),
	Azure			UMETA(DisplayName = "Azure"),
	Vert 			UMETA(DisplayName = "Vert"),
	Purpure			UMETA(DisplayName = "Purpure"),
	Sable			UMETA(DisplayName = "Sable")
};

UENUM(BlueprintType)
enum class EBlazonPattern : uint8
{
	Plain				UMETA(DisplayName = "Plain"),
	Barry				UMETA(DisplayName = "Barry"),
	Bendy				UMETA(DisplayName = "Bendy"),
	Chequey				UMETA(DisplayName = "Chequey"),
	Chevronny			UMETA(DisplayName = "Chevronny"),
	Fretty				UMETA(DisplayName = "Fretty"),
	Gyronny				UMETA(DisplayName = "Gyronny"),
	Lozengy				UMETA(DisplayName = "Lozengy"),
	Paly				UMETA(DisplayName = "Paly"),
	Semy 				UMETA(DisplayName = "Semy"),
	PerFess				UMETA(DisplayName = "per Fess"),
	PerPale 			UMETA(DisplayName = "per Pale"),
	PerBend 			UMETA(DisplayName = "per Bend"),
	PerBendSinister		UMETA(DisplayName = "per Bend sinister"),
	PerCross 			UMETA(DisplayName = "per Cross"),
	PerSaltire			UMETA(DisplayName = "per Saltire"),
	PerChevron			UMETA(DisplayName = "per Chevron"),
	PerChevronInverted	UMETA(DisplayName = "per Chevron inverted")
};

UENUM(BlueprintType)
enum class EBlazonDivision : uint8
{
	None				UMETA(DisplayName = "None"),
	PerFess				UMETA(DisplayName = "per Fess"),
	PerPale 			UMETA(DisplayName = "per Pale"),
	PerCross 			UMETA(DisplayName = "per Cross")
};

UENUM(BlueprintType)
enum class EBlazonArrangement : uint8
{
	None				UMETA(DisplayName = "None"),
	InFess				UMETA(DisplayName = "in Fess"),
	InPale 				UMETA(DisplayName = "in Pale"),
	InBend				UMETA(DisplayName = "in Bend"),
	InBendSinister 		UMETA(DisplayName = "in Bend sinister"),
	InCross 			UMETA(DisplayName = "in Cross"),
	InSaltire 			UMETA(DisplayName = "in Saltire"),
	InChevron			UMETA(DisplayName = "in Chevron"),
	InChevronInverted 	UMETA(DisplayName = "in Chevron inverted"),
	InPall				UMETA(DisplayName = "in Pall"),
	InPallInverted 		UMETA(DisplayName = "in Pall inverted"),
};

UENUM(BlueprintType)
enum class EBlazonLocation : uint8
{
	None				UMETA(DisplayName = "None"),
	InCenter 			UMETA(DisplayName = "in Center"),
	InChief				UMETA(DisplayName = "in Chief"),
	InBase 				UMETA(DisplayName = "in Base"),
	InDexter 			UMETA(DisplayName = "in Dexter"),
	InSinister			UMETA(DisplayName = "in Sinister"),
	InCanton 			UMETA(DisplayName = "in Canton"),
	InSinisterCanton 	UMETA(DisplayName = "in sinister Canton"),
};

UENUM(BlueprintType)
enum class EBlazonOrientation : uint8
{
	None				UMETA(DisplayName = "None"),
	Fesswise			UMETA(DisplayName = "Fesswise"),
	Palewise			UMETA(DisplayName = "Palewise"),
	Bendwise			UMETA(DisplayName = "Bendwise"),
	BendSinisterwise	UMETA(DisplayName = "Bend sinisterwise"),
	InCross 			UMETA(DisplayName = "in Cross"),
	InSaltire 			UMETA(DisplayName = "in Saltire"),
	InChevron			UMETA(DisplayName = "in Chevron"),
	InChevronInverted 	UMETA(DisplayName = "in Chevron inverted"),
	InPall				UMETA(DisplayName = "in Pall"),
	InPallInverted 		UMETA(DisplayName = "in Pall inverted"),
	ToChief				UMETA(DisplayName = "to Chief"),
	ToBase				UMETA(DisplayName = "to Base"),
	ToDexter			UMETA(DisplayName = "to Dexter"),
	ToSinister			UMETA(DisplayName = "to Sinister"),
};

UENUM(BlueprintType)
enum class EBlazonChargeType : uint8
{
	None			UMETA(DisplayName = "None"),
	Animate			UMETA(DisplayName = "Animate"),
	Inanimate		UMETA(DisplayName = "Inanimate"),
	Ordinary		UMETA(DisplayName = "Ordinary")
};

UENUM(BlueprintType)
enum class EBlazonAnimateCharge : uint8
{
	None			UMETA(DisplayName = "None"),
	Lion 			UMETA(DisplayName = "Lion"),
	Dragon			UMETA(DisplayName = "Dragon"),
	Eagle			UMETA(DisplayName = "Eagle"),
	Stag			UMETA(DisplayName = "Stag"),
	Wolf			UMETA(DisplayName = "Wolf"),
	Bear			UMETA(DisplayName = "Bear"),
	Boar 			UMETA(DisplayName = "Boar"),
	Bee				UMETA(DisplayName = "Bee"),
	Sheep			UMETA(DisplayName = "Sheep"),
	Bull 			UMETA(DisplayName = "Bull"),
	Horse			UMETA(DisplayName = "Horse"),
	Fish			UMETA(DisplayName = "Fish"),
	Crab			UMETA(DisplayName = "Crab"),
	Serpent			UMETA(DisplayName = "Serpent"),
	Crow 			UMETA(DisplayName = "Crow"),
	Owl				UMETA(DisplayName = "Owl"),
	Griffin			UMETA(DisplayName = "Griffin"),
	Unicorn			UMETA(DisplayName = "Unicorn"),
	Phoenix			UMETA(DisplayName = "Phoenix"),
	Saint			UMETA(DisplayName = "Saint"),
};

UENUM(BlueprintType)
enum class EBlazonInanimateCharge : uint8
{
	None			UMETA(DisplayName = "None"),
	Sword 			UMETA(DisplayName = "Sword"),
	ChurchBell		UMETA(DisplayName = "Church Bell"),
	Ship			UMETA(DisplayName = "Ship"),
	Castle			UMETA(DisplayName = "Castle"),
	Tower			UMETA(DisplayName = "Tower"),
	ShootingStar	UMETA(DisplayName = "Shooting Star"),
	Sun				UMETA(DisplayName = "Sun"),
	Moon			UMETA(DisplayName = "Moon"),
	Gauntlet		UMETA(DisplayName = "Gauntlet"),
	Anchor			UMETA(DisplayName = "Anchor"),
	Rose 			UMETA(DisplayName = "Rose"),
	Tree 			UMETA(DisplayName = "Tree"),
	Cross 			UMETA(DisplayName = "Cross"),
	CrossPatee		UMETA(DisplayName = "Cross Patee"),
	CrossCrosslet	UMETA(DisplayName = "Cross Crosslet"),
	CrossFlory		UMETA(DisplayName = "Cross Flory"),
	Crescent 		UMETA(DisplayName = "Crescent"),
	Mullet 			UMETA(DisplayName = "Mullet"),
	MulletPierced 	UMETA(DisplayName = "Mullet Pierced"),
	Lozenge 		UMETA(DisplayName = "Lozenge"),
	Roundel 		UMETA(DisplayName = "Roundel"),
	FleurDeLis		UMETA(DisplayName = "Fleur-de-lis")
};

/*
UENUM(BlueprintType)
enum class EBlazonOrdinaryCharge : uint8
{
	None			UMETA(DisplayName = "None"),
	Chief 			UMETA(DisplayName = "Chief"),
	Fess 			UMETA(DisplayName = "Fess"),
	Pale 			UMETA(DisplayName = "Pale"),
	Bend 			UMETA(DisplayName = "Bend"),
	BendSinister 	UMETA(DisplayName = "Bend Sinister"),
	Cross 			UMETA(DisplayName = "Cross"),
	Chevron 		UMETA(DisplayName = "Chevron"),
	Saltire 		UMETA(DisplayName = "Saltire"),
	Pile 			UMETA(DisplayName = "Pile"),
	Flaunches 		UMETA(DisplayName = "Flaunches")
};
*/

UENUM(BlueprintType)
enum class EBlazonOrdinaryCharge : uint8
{
	None				UMETA(DisplayName = "None"),
	AFess				UMETA(DisplayName = "Fess"),
	APale				UMETA(DisplayName = "Pale"),
	ABend 				UMETA(DisplayName = "Bend"),
	ABendSinister		UMETA(DisplayName = "Bend sinister"),
	ACross				UMETA(DisplayName = "Cross"),
	ASaltire 			UMETA(DisplayName = "Saltire"),
	AChevron			UMETA(DisplayName = "Chevron"),
	AChevronInverted 	UMETA(DisplayName = "Chevron inverted"),
	APall 				UMETA(DisplayName = "Pall"),
	APallInverted 		UMETA(DisplayName = "Pall inverted"),
	AChief 				UMETA(DisplayName = "Chief"),
	ABase				UMETA(DisplayName = "Base"),
	ACanton 			UMETA(DisplayName = "Canton"),
	ASinisterCanton 	UMETA(DisplayName = "sinister Canton"),
	Pile 				UMETA(DisplayName = "Pile"),
	Flaunches 			UMETA(DisplayName = "Flaunches")
};
