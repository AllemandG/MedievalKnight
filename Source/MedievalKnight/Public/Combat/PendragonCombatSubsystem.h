#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Core/PendragonOpposedCheck.h"
#include "PendragonNPCData.h"
#include "PendragonCombatSubsystem.generated.h"

class UPendragonCharacterComponent;
class UPendragonInventoryComponent;

UENUM(BlueprintType)
enum class ECombatState : uint8
{
    NotStarted,
    PlayerTurn,
    ResolvingRound,
    CombatEnded
};

/** Log détaillé de ce qui s'est passé durant le round */
USTRUCT(BlueprintType)
struct FCombatRoundLog
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "Combat")
    int32 RoundNumber = 1;

    UPROPERTY(BlueprintReadOnly, Category = "Combat")
    FOpposedCheckResult CheckResult;

    UPROPERTY(BlueprintReadOnly, Category = "Combat")
    int32 RawDamageDealt = 0;

    UPROPERTY(BlueprintReadOnly, Category = "Combat")
    int32 ArmorAbsorbed = 0;

    UPROPERTY(BlueprintReadOnly, Category = "Combat")
    int32 FinalDamageTaken = 0;

    UPROPERTY(BlueprintReadOnly, Category = "Combat")
    bool bIsMajorWound = false;

    UPROPERTY(BlueprintReadOnly, Category = "Combat")
    bool bTargetKnockedUnconscious = false;

    UPROPERTY(BlueprintReadOnly, Category = "Combat")
    FText LogMessage;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatStateChanged, ECombatState, NewState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatRoundResolved, const FCombatRoundLog&, RoundLog);

UCLASS()
class MEDIEVALKNIGHT_API UPendragonCombatSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, Category = "Pendragon|Combat")
    FOnCombatStateChanged OnCombatStateChanged;

    UPROPERTY(BlueprintAssignable, Category = "Pendragon|Combat")
    FOnCombatRoundResolved OnCombatRoundResolved;

    /** Démarrer un combat 1v1 contre un PNJ */
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Combat")
    void StartCombat(UPendragonCharacterComponent* PlayerChar, UPendragonInventoryComponent* PlayerInv, const FPendragonNPC& Enemy);

    /** 
     * Exécute le round de combat avec une tactique spécifique
     * @param Tactic Posture tactique choisie pour ce round
     * @param SkillUsed Compétence utilisée (Épée, Lance, etc.)
     */
    UFUNCTION(BlueprintCallable, Category = "Pendragon|Combat")
    void ExecutePlayerAttack(EPendragonCombatTactic Tactic = EPendragonCombatTactic::Normal, FName SkillUsed = TEXT("Sword"));

    /** Active/Désactive l'état monté pour la charge à la lance */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Combat")
    bool bPlayerIsMounted = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pendragon|Combat")
    bool bEnemyIsMounted = false;

protected:
    UPROPERTY()
    UPendragonCharacterComponent* PlayerCharacterComp;

    UPROPERTY()
    UPendragonInventoryComponent* PlayerInventoryComp;

    UPROPERTY(BlueprintReadOnly, Category = "Pendragon|Combat")
    FPendragonNPC CurrentEnemy;

    UPROPERTY(BlueprintReadOnly, Category = "Pendragon|Combat")
    ECombatState CurrentState = ECombatState::NotStarted;

    UPROPERTY(BlueprintReadOnly, Category = "Pendragon|Combat")
    int32 CurrentRound = 0;

    /** Lance X dés à 6 faces */
    int32 RollDice(int32 NumDice) const;
};