#pragma once

#include "CoreMinimal.h"
#include "PendragonTypes.h"
#include "UObject/Object.h"
#include "PendragonCharacterCreationSubsystem.generated.h"

class UPendragonCharacterComponent;
class UPendragonInventoryComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCreationDataChanged);

UCLASS()
class MEDIEVALKNIGHT_API UPendragonCharacterCreationSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "Pendragon|Creation")
	FOnCreationDataChanged OnCreationDataChanged;

	/** Initialiser une nouvelle session de création */
	UFUNCTION(BlueprintCallable, Category = "Pendragon|Creation")
	void StartNewCreation();

	/** Obtenir les données actuelles en lecture/écriture */
	UFUNCTION(BlueprintPure, Category = "Pendragon|Creation")
	const FPendragonCreationData& GetCreationData() const { return CreationData; }

	/** Modifier un attribut principal (ex: STR, DEX...) */
	UFUNCTION(BlueprintCallable, Category = "Pendragon|Creation")
	bool ModifyAttribute(FName AttributeName, int32 Delta);

	/** Modifier une compétence */
	UFUNCTION(BlueprintCallable, Category = "Pendragon|Creation")
	bool ModifySkill(FName SkillName, int32 Delta);

	/** Ajouter un lien familial / féodal */
	UFUNCTION(BlueprintCallable, Category = "Pendragon|Creation")
	void AddFamilyLink(const FPendragonFamilyLink& NewLink);

	/** Finaliser la création et injecter les données dans les composants du joueur */
	UFUNCTION(BlueprintCallable, Category = "Pendragon|Creation")
	bool FinalizeCharacterCreation(UPendragonCharacterComponent* TargetCharacterComp, UPendragonInventoryComponent* TargetInventoryComp);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Pendragon|Creation")
	FPendragonCreationData CreationData;
};