#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MedievalPlayerController.generated.h"

class UPendragonCharacterComponent;

UCLASS()
class MEDIEVALKNIGHT_API AMedievalPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMedievalPlayerController();

	// Composant principal gérant les attributs, traits, passions et compétences du chevalier
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pendragon|Character", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPendragonCharacterComponent> CharacterComponent;

	// Helper pour récupérer rapidement le composant depuis les Blueprints ou l'UI
	UFUNCTION(BlueprintPure, Category = "Pendragon|Character")
	UPendragonCharacterComponent* GetCharacterComponent() const { return CharacterComponent; }
};