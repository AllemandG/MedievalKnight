#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MedievalPlayerController.generated.h"

class UCharacterComponent;

UCLASS()
class MEDIEVALKNIGHT_API AMedievalPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMedievalPlayerController();

	virtual void BeginPlay() override;

	// Composant principal gérant les attributs, traits, passions et compétences du chevalier
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pendragon|Character", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCharacterComponent> CharacterComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pendragon|Character", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInventoryComponent> InventoryComponent;

	// Helper pour récupérer rapidement le composant depuis les Blueprints ou l'UI
	UFUNCTION(BlueprintPure, Category = "Pendragon|Character")
	UCharacterComponent* GetCharacterComponent() const { return CharacterComponent; }
};