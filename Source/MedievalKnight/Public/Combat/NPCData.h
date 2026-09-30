#pragma once

#include "CoreMinimal.h"
#include "Core/MedievalKnightTypes.h"
#include "Items/InventoryTypes.h"
#include "NPCData.generated.h"

USTRUCT(BlueprintType)
struct FPendragonNPC
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	FText Name = FText::FromString(TEXT("Enemy Knight"));
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	FText Culture = FText::FromString(TEXT("English"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	int32 BirthYear = 1315;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	bool bIsNoble = false;

	// Attributs principaux
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	int32 Size = 12;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	int32 Dexterity = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	int32 Strength = 14;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	int32 Constitution = 12;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	int32 Appeal = 12;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	int32 CurrentHealth = 26;

	// Compétence de combat principale (ex: Épée / Lance)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	int32 CombatSkillValue = 13;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC|Skills")
	TMap<FName, FSkillData> CharacterSkills;

	// Équipement & Protection
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	int32 ArmorProtection = 10; // ex: Haubert de maille (10)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC")
	int32 ShieldProtection = 0;  // ex: Bouclier (+6)

	// Calculs dérivés
	int32 GetKnockdown () const { return Size; }
	int32 GetDamageDice() const { return RoundDivide(Size + Strength, 6); }
	int32 GetBrawlingDamage() const { return RoundDivide(Size + Strength, 6); }
	int32 GetMovementRate() const { return (RoundDivide(Strength + Dexterity, 2)+5); }
	int32 GetMajorWoundThreshold() const { return Constitution; }
	int32 GetHealRate() const { return FMath::Max(1, RoundDivide(Constitution, 5)); }
	int32 GetMaxHealth() const { return Constitution + Size; }
	int32 GetUnconscious() const { return RoundDivide(GetMaxHealth(),4); }

	static FORCEINLINE int32 RoundDivide(int32 Dividend, int32 Divisor)
	{
		if (Divisor == 0) return 0;
		return FMath::RoundToInt(static_cast<float>(Dividend) / static_cast<float>(Divisor));
	}
};