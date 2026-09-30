#include "Core/MedievalKnightCharacter.h"
#include "Components/CharacterComponent.h"
#include "Components/InventoryComponent.h"

AMedievalKnightCharacter::AMedievalKnightCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	// Instanciation automatique des sous-composants
	CharacterComponent = CreateDefaultSubobject<UCharacterComponent>(TEXT("CharacterComponent"));
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
}
