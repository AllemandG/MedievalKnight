#include "Combat/PendragonCombatSubsystem.h"
#include "Components/PendragonCharacterComponent.h"
#include "Components/PendragonInventoryComponent.h"

void UPendragonCombatSubsystem::StartCombat(UPendragonCharacterComponent* PlayerChar, UPendragonInventoryComponent* PlayerInv, const FPendragonNPC& Enemy)
{
    PlayerCharacterComp = PlayerChar;
    PlayerInventoryComp = PlayerInv;
    CurrentEnemy = Enemy;
    CurrentRound = 1;

    CurrentState = ECombatState::PlayerTurn;
    OnCombatStateChanged.Broadcast(CurrentState);
}

int32 UPendragonCombatSubsystem::RollDice(int32 NumDice) const
{
    int32 Total = 0;
    for (int32 i = 0; i < NumDice; ++i)
    {
        Total += FMath::RandRange(1, 6);
    }
    return Total;
}

void UPendragonCombatSubsystem::ExecutePlayerAttack(FName SkillUsed)
{
    if (CurrentState != ECombatState::PlayerTurn || !PlayerCharacterComp) return;

    CurrentState = ECombatState::ResolvingRound;
    OnCombatStateChanged.Broadcast(CurrentState);

    FCombatRoundLog Log;
    Log.RoundNumber = CurrentRound;

    // 1. Récupération des valeurs de compétence
    int32 PlayerSkill = PlayerCharacterComp->GetSkillValue(SkillUsed);
    int32 EnemySkill = CurrentEnemy.CombatSkillValue;

    // 2. Résolution du jet opposé
    Log.CheckResult = UPendragonOpposedCheck::ResolveOpposedCheck(PlayerSkill, EnemySkill);

    // 3. Résolution des dégâts
    if (Log.CheckResult.Outcome == EOpposedOutcome::AttackerWins)
    {
        // Le joueur l'emporte
        int32 DiceToRoll = PlayerCharacterComp->GetDamageBonus();
        if (Log.CheckResult.Attacker.Quality == EPendragonCheckResult::CriticalSuccess)
        {
            DiceToRoll *= 2; // Dégâts doublés en Critique selon la 6e
        }

        Log.RawDamageDealt = RollDice(DiceToRoll);
        Log.ArmorAbsorbed = CurrentEnemy.ArmorProtection + CurrentEnemy.ShieldProtection;
        Log.FinalDamageTaken = FMath::Max(0, Log.RawDamageDealt - Log.ArmorAbsorbed);

        CurrentEnemy.CurrentHealth -= Log.FinalDamageTaken;
        Log.bIsMajorWound = (Log.FinalDamageTaken >= CurrentEnemy.GetMajorWoundThreshold());

        // Coche la compétence d'épée/combat du joueur pour la phase d'hiver
        PlayerCharacterComp->CheckSkillForImprovement(SkillUsed);

        Log.LogMessage = FText::FromString(FString::Printf(TEXT("Vous touchez %s et infligez %d dégâts (%d absorbés)."), 
            *CurrentEnemy.Name.ToString(), Log.FinalDamageTaken, Log.ArmorAbsorbed));
    }
    else if (Log.CheckResult.Outcome == EOpposedOutcome::DefenderWins)
    {
        // Le PNJ l'emporte
        int32 DiceToRoll = CurrentEnemy.GetDamageDice();
        if (Log.CheckResult.Defender.Quality == EPendragonCheckResult::CriticalSuccess)
        {
            DiceToRoll *= 2;
        }

        Log.RawDamageDealt = RollDice(DiceToRoll);
        Log.ArmorAbsorbed = PlayerInventoryComp ? PlayerInventoryComp->GetTotalKnightArmorProtection() : 0;
        Log.FinalDamageTaken = FMath::Max(0, Log.RawDamageDealt - Log.ArmorAbsorbed);

        PlayerCharacterComp->Attributes.CurrentHealth -= Log.FinalDamageTaken;
        Log.bIsMajorWound = (Log.FinalDamageTaken >= PlayerCharacterComp->Attributes.Constitution);

        Log.LogMessage = FText::FromString(FString::Printf(TEXT("%s vous touche et inflige %d dégâts (%d absorbés par votre armure)."), 
            *CurrentEnemy.Name.ToString(), Log.FinalDamageTaken, Log.ArmorAbsorbed));
    }
    else
    {
        Log.LogMessage = FText::FromString(TEXT("Égalité ! Vos armes se heurtent sans infliger de dégâts."));
    }

    // 4. Vérification de fin de combat
    if (CurrentEnemy.CurrentHealth <= 0 || PlayerCharacterComp->Attributes.CurrentHealth <= 0)
    {
        CurrentState = ECombatState::CombatEnded;
    }
    else
    {
        CurrentRound++;
        CurrentState = ECombatState::PlayerTurn;
    }

    OnCombatRoundResolved.Broadcast(Log);
    OnCombatStateChanged.Broadcast(CurrentState);
}