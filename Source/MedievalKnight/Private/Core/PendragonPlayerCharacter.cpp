#include "Core/PendragonPlayerCharacter.h"
#include "Components/PendragonCharacterComponent.h"
#include "Components/PendragonInventoryComponent.h"

APendragonPlayerCharacter::APendragonPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	// Instanciation automatique des sous-composants
	CharacterComponent = CreateDefaultSubobject<UPendragonCharacterComponent>(TEXT("CharacterComponent"));
	InventoryComponent = CreateDefaultSubobject<UPendragonInventoryComponent>(TEXT("InventoryComponent"));
}
