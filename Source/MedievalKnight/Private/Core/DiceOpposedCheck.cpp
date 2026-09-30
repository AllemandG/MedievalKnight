#include "Core/DiceOpposedCheck.h"

FOpposedCheckParticipantResult UDiceOpposedCheck::EvaluateSingleParticipant(int32 TargetValue, int32 DiceRoll)
{
    FOpposedCheckParticipantResult Result;
    Result.TargetValue = TargetValue;
    Result.DiceRoll = DiceRoll;

    // Calcul des bonus/malus pour les valeurs supérieures à 20
    int32 ValueBonus = 0;
    int32 EffectiveTarget = TargetValue;

    if (TargetValue > 20)
    {
        ValueBonus = TargetValue - 20;
        EffectiveTarget = 20;
    }

    // Résolution de la qualité du jet
    if (DiceRoll == 20)
    {
        // En 6e édition, 20 est toujours un Fumble sauf si le Target effectif est de 20
        if (EffectiveTarget == 20)
        {
            Result.Quality = EDiceCheckResult::CriticalSuccess;
        }
        else
        {
            Result.Quality = EDiceCheckResult::Fumble;
        }
    }
    else if (DiceRoll == EffectiveTarget)
    {
        Result.Quality = EDiceCheckResult::CriticalSuccess;
    }
    else if (DiceRoll < EffectiveTarget)
    {
        Result.Quality = EDiceCheckResult::Success;
    }
    else
    {
        Result.Quality = EDiceCheckResult::Failure;
    }

    // Calcul du Score Effectif d'opposition
    switch (Result.Quality)
    {
    case EDiceCheckResult::CriticalSuccess:
        // En cas de compétence > 20, le bonus s'ajoute au score du Critique (ex: 20 + 2 = 22)
        Result.EffectiveScore = 21 + ValueBonus;
        break;

    case EDiceCheckResult::Success:
        // Le score effectif est la valeur du dé + le bonus si compétence > 20
        Result.EffectiveScore = DiceRoll + ValueBonus;
        break;

    case EDiceCheckResult::Failure:
        Result.EffectiveScore = 0;
        break;

    case EDiceCheckResult::Fumble:
        Result.EffectiveScore = -1;
        break;
    }

    return Result;
}

FOpposedCheckResult UDiceOpposedCheck::ResolveOpposedCheck(int32 AttackerTarget, int32 DefenderTarget)
{
    FOpposedCheckResult FinalResult;

    // Lancer de dés d20
    int32 AttackerRoll = FMath::RandRange(1, 20);
    int32 DefenderRoll = FMath::RandRange(1, 20);

    FinalResult.Attacker = EvaluateSingleParticipant(AttackerTarget, AttackerRoll);
    FinalResult.Defender = EvaluateSingleParticipant(DefenderTarget, DefenderRoll);

    // Détermination du vainqueur selon les scores effectifs
    if (FinalResult.Attacker.EffectiveScore > FinalResult.Defender.EffectiveScore)
    {
        FinalResult.Outcome = EOpposedOutcome::AttackerWins;
    }
    else if (FinalResult.Defender.EffectiveScore > FinalResult.Attacker.EffectiveScore)
    {
        FinalResult.Outcome = EOpposedOutcome::DefenderWins;
    }
    else
    {
        // Scores égaux
        if (FinalResult.Attacker.Quality == EDiceCheckResult::Fumble && 
            FinalResult.Defender.Quality == EDiceCheckResult::Fumble)
        {
            FinalResult.Outcome = EOpposedOutcome::BothFumbled;
        }
        else
        {
            FinalResult.Outcome = EOpposedOutcome::Tie;
        }
    }

    FinalResult.MarginOfVictory = FinalResult.Attacker.EffectiveScore - FinalResult.Defender.EffectiveScore;

    return FinalResult;
}