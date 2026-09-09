#include "MedievalKnight/Public/MedievalKnightGameModeBase.h"
#include "MedievalKnight/Public/Player/MedievalPlayerController.h"

AMedievalKnightGameModeBase::AMedievalKnightGameModeBase()
{
	// Définit notre PlayerController C++ comme classe par défaut
	PlayerControllerClass = AMedievalPlayerController::StaticClass();
}
