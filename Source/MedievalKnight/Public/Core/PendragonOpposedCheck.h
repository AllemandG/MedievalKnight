#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PendragonTypes.h"
#include "PendragonOpposedCheck.generated.h"

/** Résultat détaillé pour un participant à un jet opposé */
USTRUCT(BlueprintType)
struct FOpposedCheckParticipantResult
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "Pendragon|Check")
    int32 TargetValue = 10;

    UPROPERTY(BlueprintReadOnly, Category = "Pendragon|Check")
    int32 DiceRoll = 0;

    UPROPERTY(BlueprintReadOnly, Category = "Pendragon|Check")
    EPendragonCheckResult Quality = EPendragonCheckResult::Failure;

    /** Score effectif utilisé pour départager (Critique = 21, Succès = Valeur du Dé, Échec = 0, Fumble = -1) */
    UPROPERTY(BlueprintReadOnly, Category = "Pendragon|Check")
    int32 EffectiveScore = 0;
};

/** Résultat global de l'opposition */
UENUM(BlueprintType)
enum class EOpposedOutcome : uint8
{
    AttackerWins,
    DefenderWins,
    Tie,            // Égalité (Parade mutuelle en combat)
    BothFumbled     // Les deux ont fait un Fumble
};

USTRUCT(BlueprintType)
struct FOpposedCheckResult
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "Pendragon|Check")
    FOpposedCheckParticipantResult Attacker;

    UPROPERTY(BlueprintReadOnly, Category = "Pendragon|Check")
    FOpposedCheckParticipantResult Defender;

    UPROPERTY(BlueprintReadOnly, Category = "Pendragon|Check")
    EOpposedOutcome Outcome = EOpposedOutcome::Tie;

    /** Marge de victoire (Score Attaquant - Score Défenseur) */
    UPROPERTY(BlueprintReadOnly, Category = "Pendragon|Check")
    int32 MarginOfVictory = 0;
};

UCLASS()
class MEDIEVALKNIGHT_API UPendragonOpposedCheck : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    /**
     * Effectue un jet opposé complet entre un attaquant (ou initiateur) et un défenseur.
     * @param AttackerTarget Valeur de compétence/attribut de l'attaquant (avec modificateurs)
     * @param DefenderTarget Valeur de compétence/attribut du défenseur (avec modificateurs)
     */
    UFUNCTION(BlueprintCallable, Category = "Pendragon|OpposedCheck")
    static FOpposedCheckResult ResolveOpposedCheck(int32 AttackerTarget, int32 DefenderTarget);

    /** Évalue un jet d20 individuel pour obtenir la qualité et le score effectif d'opposition */
    static FOpposedCheckParticipantResult EvaluateSingleParticipant(int32 TargetValue, int32 DiceRoll);
};