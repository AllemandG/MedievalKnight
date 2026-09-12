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
	/** Nombre total de choix d'augmentation restants (commence à 7) */
	UPROPERTY(BlueprintReadOnly, Category = "Pendragon|Creation")
	int32 RemainingAugmentationChoices = 7;
	
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

	/** Modifier un Trait spécifique par son nom (ex: "Valorous") */
	UFUNCTION(BlueprintCallable, Category = "Pendragon|Creation")
	bool ModifyTrait(EPendragonTrait PrimaryTrait, int32 Delta);

	/** Modifier une Passion par son nom (ex: "Loyalty (Lord)") */
	UFUNCTION(BlueprintCallable, Category = "Pendragon|Creation")
	bool ModifyPassion(FName PassionName, int32 Delta);

	/** Applique une augmentation d'Attribut (ex: +1 Force) */
	UFUNCTION(BlueprintCallable, Category = "Pendragon|Creation")
	bool ApplyAttributeAugmentation(EPendragonAttribute Attribute);

	/** Applique une augmentation de Points de Compétences (+6 au pool de compétences) */
	UFUNCTION(BlueprintCallable, Category = "Pendragon|Creation")
	bool ApplySkillPointsAugmentation();

	/** Applique un bonus de caractéristique familiale (+3 sur une compétence donnée) */
	UFUNCTION(BlueprintCallable, Category = "Pendragon|Creation")
	void ApplyFamilyBonus(FName SkillName, int32 BonusAmount = 3);

	/** Génère aléatoirement l'historique du père (ou attribue des valeurs par défaut) */
	UFUNCTION(BlueprintCallable, Category = "Pendragon|Creation")
	void GenerateParentHistory();

	/** Calcule la somme actuelle des traits chevaleresques */
	UFUNCTION(BlueprintPure, Category = "Pendragon|Creation")
	int32 GetChivalryTraitsSum() const;

	/** Vérifie si le personnage remplit les conditions du Bonus Chevaleresque (Somme >= 80) */
	UFUNCTION(BlueprintPure, Category = "Pendragon|Creation")
	bool IsEligibleForChivalryBonus() const { return GetChivalryTraitsSum() >= 80; }

	/** Vérifie si le personnage remplit les conditions du Bonus Religieux (5 traits à 16+) */
	UFUNCTION(BlueprintPure, Category = "Pendragon|Creation")
	bool IsEligibleForReligiousBonus() const;

	/** Ajouter un lien familial / féodal */
	UFUNCTION(BlueprintCallable, Category = "Pendragon|Creation")
	void AddFamilyLink(const FPendragonFamilyLink& NewLink);

	/** Finaliser la création et injecter les données dans les composants du joueur */
	UFUNCTION(BlueprintCallable, Category = "Pendragon|Creation")
	bool FinalizeCharacterCreation(UPendragonCharacterComponent* TargetCharacterComp, UPendragonInventoryComponent* TargetInventoryComp);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Pendragon|Creation")
	FPendragonCreationData CreationData;

	// Copie de travail des traits durant la création
	UPROPERTY(BlueprintReadOnly, Category = "Pendragon|Creation")
	TArray<FPendragonTraitPair> CreationTraits;
};