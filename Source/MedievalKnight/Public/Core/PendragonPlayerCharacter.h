#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/PendragonCharacterComponent.h"
#include "Components/PendragonInventoryComponent.h"
#include "PendragonPlayerCharacter.generated.h"

UCLASS()
class MEDIEVALKNIGHT_API APendragonPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APendragonPlayerCharacter();

	/** Composant gérant les statistiques, traits, passions et compétences */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pendragon|Components", meta = (AllowPrivateAccess = "true"))
	UPendragonCharacterComponent* CharacterComponent;

	/** Composant gérant l'inventaire et les objets équipés */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pendragon|Components", meta = (AllowPrivateAccess = "true"))
	UPendragonInventoryComponent* InventoryComponent;

	/** Getters d'accès rapide aux composants */
	FORCEINLINE UPendragonCharacterComponent* GetCharacterComponent() const { return CharacterComponent; }
	FORCEINLINE UPendragonInventoryComponent* GetInventoryComponent() const { return InventoryComponent; }
};
