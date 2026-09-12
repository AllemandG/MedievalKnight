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

void UPendragonCombatSubsystem::ExecutePlayerAttack(EPendragonCombatTactic Tactic, FName SkillUsed)
{
    if (CurrentState != ECombatState::PlayerTurn || !PlayerCharacterComp) return;

    CurrentState = ECombatState::ResolvingRound;
    OnCombatStateChanged.Broadcast(CurrentState);

    FCombatRoundLog Log;
    Log.RoundNumber = CurrentRound;

    // 1. Calcul des scores de compétence de base
    int32 PlayerSkill = PlayerCharacterComp->GetSkillValue(SkillUsed);
    int32 EnemySkill = CurrentEnemy.CombatSkillValue;

    // 2. Application des modificateurs tactiques
    int32 PlayerDamageBonus = 0;

    switch (Tactic)
    {
    case EPendragonCombatTactic::AllOutAttack:
        PlayerSkill -= 5;
        PlayerDamageBonus += 4;
        break;

    case EPendragonCombatTactic::Defensive:
        PlayerSkill += 5;
        break;

    case EPendragonCombatTactic::Prudent:
        PlayerSkill += 2;
        break;

    default:
        break;
    }

    // 3. Résolution du jet opposé
    Log.CheckResult = UPendragonOpposedCheck::ResolveOpposedCheck(PlayerSkill, EnemySkill);

    FString AttackerResultStr = FString::Printf(TEXT("Attaquant : %d (Dé: %d)"), Log.CheckResult.Attacker.TargetValue, Log.CheckResult.Attacker.DiceRoll);
    FString DefenderResultStr = FString::Printf(TEXT("Défenseur : %d (Dé: %d)"), Log.CheckResult.Defender.TargetValue, Log.CheckResult.Defender.DiceRoll);
    
    // 4. Traitement des dégâts
    if (Log.CheckResult.Outcome == EOpposedOutcome::AttackerWins)
    {
        if (Tactic == EPendragonCombatTactic::Defensive)
        {
            // En posture défensive, une victoire permet seulement d'annuler les dégâts adverses
            Log.LogMessage = FText::FromString(FString::Printf(
                TEXT("<Gold>PARADE !</> Vous bloquez l'attaque adverse grâce à votre posture défensive. [%s vs %s]"), 
                *AttackerResultStr, *DefenderResultStr));
            Log.FinalDamageTaken = 0;
        }
        else
        {
            int32 DiceToRoll;

            if (SkillUsed == "Brawling")
            {
                DiceToRoll = PlayerCharacterComp->GetBrawlingDamage() + PlayerInventoryComp->EquippedSlots.Find(EEquipmentSlot::MainHand)->EquippedWeapon.BonusDamage;
            }
            else
            {
                DiceToRoll = PlayerCharacterComp->GetDamageDice() + PlayerInventoryComp->EquippedSlots.Find(EEquipmentSlot::MainHand)->EquippedWeapon.BonusDamage;
            }
            
            // Dégâts doublés en Critique
            bool bIsCritical = (Log.CheckResult.Attacker.Quality == EPendragonCheckResult::CriticalSuccess);
        
            if (bIsCritical) DiceToRoll *= 2;

            Log.RawDamageDealt = RollDice(DiceToRoll) + PlayerDamageBonus + PlayerInventoryComp->EquippedSlots.Find(EEquipmentSlot::MainHand)->EquippedWeapon.FlatDamage;
            Log.ArmorAbsorbed = CurrentEnemy.ArmorProtection + CurrentEnemy.ShieldProtection;
            Log.FinalDamageTaken = FMath::Max(0, Log.RawDamageDealt - Log.ArmorAbsorbed);

            CurrentEnemy.CurrentHealth -= Log.FinalDamageTaken;
            Log.bIsMajorWound = (Log.FinalDamageTaken >= CurrentEnemy.GetMajorWoundThreshold());

            PlayerCharacterComp->CheckSkillForImprovement(SkillUsed);

            FString BaseRollInfo = FString::Printf(TEXT("<Italic>(Jet: %d vs %d)</>"), Log.CheckResult.Attacker.DiceRoll, Log.CheckResult.Defender.DiceRoll);

            if (Log.bIsMajorWound)
            {
                Log.LogMessage = FText::FromString(FString::Printf(
                    TEXT("<Gold>COUP TERRIBLE !</> Vous infligez <Green>%d dégâts</> à %s <Gray>(%d absorbés)</>. <Red>BLESSURE MAJEURE !</> %s"),
                    Log.FinalDamageTaken, *CurrentEnemy.Name.ToString(), Log.ArmorAbsorbed, *BaseRollInfo));
            }
            else
            {
                Log.LogMessage = FText::FromString(FString::Printf(
                    TEXT("Vous touchez %s et infligez <Green>%d dégâts</> <Gray>(%d absorbés)</>. %s"),
                    *CurrentEnemy.Name.ToString(), Log.FinalDamageTaken, Log.ArmorAbsorbed, *BaseRollInfo));
            }
        }
    }
    else if (Log.CheckResult.Outcome == EOpposedOutcome::DefenderWins)
    {
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

        FString BaseRollInfo = FString::Printf(TEXT("<Italic>(Jet: %d vs %d)</>"), Log.CheckResult.Attacker.DiceRoll, Log.CheckResult.Defender.DiceRoll);

        if (Log.bIsMajorWound)
        {
            Log.LogMessage = FText::FromString(FString::Printf(
                TEXT("<Red>BLESSURE MAJEURE SUBIE !</> %s vous inflige <Red>%d dégâts</> <Gray>(%d absorbés)</>. %s"),
                *CurrentEnemy.Name.ToString(), Log.FinalDamageTaken, Log.ArmorAbsorbed, *BaseRollInfo));
        }
        else
        {
            Log.LogMessage = FText::FromString(FString::Printf(
                TEXT("%s vous touche et inflige <Red>%d dégâts</> <Gray>(%d absorbés)</>. %s"),
                *CurrentEnemy.Name.ToString(), Log.FinalDamageTaken, Log.ArmorAbsorbed, *BaseRollInfo));
        }
    }
    else
    {
        Log.LogMessage = FText::FromString(FString::Printf(
            TEXT("<Gray>ÉGALITÉ !</> Vos armes se heurtent sans infliger de dégâts. <Italic>(Joueur: %d | Ennemi: %d)</>"),
            Log.CheckResult.Attacker.DiceRoll, Log.CheckResult.Defender.DiceRoll));
    }

    // 5. Mise à jour de l'état
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