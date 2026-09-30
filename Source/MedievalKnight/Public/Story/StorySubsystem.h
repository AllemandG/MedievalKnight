#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MedievalKnight/Public/Story/StoryTypes.h"
#include "MedievalKnight/Public/Story/StoryNodeDataAsset.h"
#include "StorySubsystem.generated.h"

class UCharacterComponent;

// Delegates pour l'UI
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStoryNodeChanged, const UStoryNodeDataAsset*, NewNode);

// Delegate FourParams mis à jour
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnCheckResolved, EDiceCheckResult, Result, int32, RollValue, int32, TargetValue, FName, CheckName);

UCLASS()
class MEDIEVALKNIGHT_API UStorySubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, Category = "Pendragon|Story")
    FOnStoryNodeChanged OnStoryNodeChanged;

    // Déclaration du membre OnCheckResolved
    UPROPERTY(BlueprintAssignable, Category = "Pendragon|Story")
    FOnCheckResolved OnCheckResolved;

    // Démarrer la narration à partir d'un nœud donné
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Story")
    void StartStory(UStoryNodeDataAsset* StartingNode, UCharacterComponent* PlayerCharacter);

    // Sélectionner un choix par son index dans le nœud courant
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Story")
    void SelectChoice(int32 ChoiceIndex);

    // Vérifier si le joueur remplit les prérequis d'un choix
    UFUNCTION(BlueprintPure, Category = "Pendragon|Story")
    bool CanSelectChoice(const FStoryChoice& Choice) const;

    // Obtenir le nœud d'histoire actuellement chargé
    UFUNCTION(BlueprintPure, Category = "Pendragon|Story")
    const UStoryNodeDataAsset* GetCurrentNode() const { return CurrentNode; }

private:
    UPROPERTY()
    TObjectPtr<UStoryNodeDataAsset> CurrentNode;

    UPROPERTY()
    TObjectPtr<UCharacterComponent> CharacterComponent;

    // Utilitaires internes
    void ApplyEffect(const FPendragonEffect& Effect);
    bool EvaluateRequirement(const FPendragonRequirement& Req) const;
    void TransitionToNode(TSoftObjectPtr<UStoryNodeDataAsset> NextNodePtr);
};