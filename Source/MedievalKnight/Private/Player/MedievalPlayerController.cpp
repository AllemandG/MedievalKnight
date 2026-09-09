#include "MedievalKnight/Public/Player/MedievalPlayerController.h"
#include "MedievalKnight/Public/Components/PendragonCharacterComponent.h"

AMedievalPlayerController::AMedievalPlayerController()
{
	// Instanciation automatique du composant sur le Controller
	CharacterComponent = CreateDefaultSubobject<UPendragonCharacterComponent>(TEXT("PendragonCharacterComponent"));
}
