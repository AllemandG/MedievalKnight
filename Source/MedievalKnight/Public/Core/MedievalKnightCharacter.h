#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CharacterComponent.h"
#include "Components/InventoryComponent.h"
#include "MedievalKnightCharacter.generated.h"

UCLASS()
class MEDIEVALKNIGHT_API AMedievalKnightCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMedievalKnightCharacter();

	/** Composant gérant les statistiques, traits, passions et compétences */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pendragon|Components", meta = (AllowPrivateAccess = "true"))
	UCharacterComponent* CharacterComponent;

	/** Composant gérant l'inventaire et les objets équipés */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pendragon|Components", meta = (AllowPrivateAccess = "true"))
	UInventoryComponent* InventoryComponent;

	/** Getters d'accès rapide aux composants */
	FORCEINLINE UCharacterComponent* GetCharacterComponent() const { return CharacterComponent; }
	FORCEINLINE UInventoryComponent* GetInventoryComponent() const { return InventoryComponent; }
};
