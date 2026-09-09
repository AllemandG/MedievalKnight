#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MedievalKnight/Public/Story/StoryTypes.h"
#include "StoryNodeDataAsset.generated.h"

UCLASS(BlueprintType)
class MEDIEVALKNIGHT_API UStoryNodeDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	// Identifiant unique du nœud (ex: "NODE_1337_Chevauchee_01")
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story")
	FName NodeID;

	// Titre de la scène ou du lieu (ex: "Le Gué de la Somme")
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story")
	FText Title;

	// Description textuelle narrative principale
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story", meta = (MultiLine = true))
	FText Description;

	// Choix proposés au joueur sur cette page
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story")
	TArray<FStoryChoice> Choices;

	// Override de PrimaryAssetId pour simplifier le système d'Asset Manager
	virtual FPrimaryAssetId GetPrimaryAssetId() const override
	{
		return FPrimaryAssetId("StoryNode", GetFName());
	}
};