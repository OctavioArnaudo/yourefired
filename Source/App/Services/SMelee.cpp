#include "SMelee.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/DamageEvents.h"
#include "App/Controllers/CPlayerCharacterInstance.h"
#include "App/Controllers/CEnemyCharacterInstance.h"

USMelee::USMelee()
	: IdentifierName(TEXT("SMelee")), bIsActive(true), MeleeDamage(40.0f)
{
}

bool USMelee::ProcessSMelee(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USMelee] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}

bool USMelee::PerformMeleeAttack(ACharacter* Attacker)
{
	if (!IsValid(Attacker) || !Attacker->GetWorld()) return false;

	UWorld* World = Attacker->GetWorld();
	if (!World) return false;

	FVector AttackerLoc = Attacker->GetActorLocation();

	// 1. If attacker is an enemy, check distance to player pawn
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(World, 0);
	if (IsValid(PlayerPawn) && PlayerPawn != Attacker)
	{
		float Dist = FVector::Dist(AttackerLoc, PlayerPawn->GetActorLocation());
		if (Dist <= 150.0f)
		{
			UE_LOG(LogTemp, Warning, TEXT("[USMelee] Enemy melee hit Player at dist %.1f! Applying %.2f damage."), Dist, MeleeDamage);
			PerformMeleeAttackOnTarget(Attacker, PlayerPawn);
			return true;
		}
	}

	// 2. If attacker is player, check distance to enemy characters safely
	TArray<AActor*> EnemyActors;
	UGameplayStatics::GetAllActorsOfClass(World, ACEnemyCharacterInstance::StaticClass(), EnemyActors);
	for (AActor* Enemy : EnemyActors)
	{
		if (IsValid(Enemy) && Enemy != Attacker)
		{
			float Dist = FVector::Dist(AttackerLoc, Enemy->GetActorLocation());
			if (Dist <= 150.0f)
			{
				UE_LOG(LogTemp, Warning, TEXT("[USMelee] Player melee hit Enemy '%s' at dist %.1f! Applying %.2f damage."), *Enemy->GetName(), Dist, MeleeDamage);
				PerformMeleeAttackOnTarget(Attacker, Enemy);
				break;
			}
		}
	}

	return true;
}

bool USMelee::PerformMeleeAttackOnTarget(ACharacter* Attacker, AActor* Target)
{
	if (!IsValid(Attacker) || !IsValid(Target)) return false;
	UE_LOG(LogTemp, Warning, TEXT("[USMelee] '%s' melee attacks target '%s' for %.2f damage."), *Attacker->GetName(), *Target->GetName(), MeleeDamage);

	ACPlayerCharacterInstance* PlayerTarget = Cast<ACPlayerCharacterInstance>(Target);
	if (IsValid(PlayerTarget))
	{
		PlayerTarget->TakeDamage(MeleeDamage, FDamageEvent(), Attacker->GetController(), Attacker);
	}
	else
	{
		ACEnemyCharacterInstance* EnemyTarget = Cast<ACEnemyCharacterInstance>(Target);
		if (IsValid(EnemyTarget))
		{
			EnemyTarget->TakeDamage(MeleeDamage, FDamageEvent(), Attacker->GetController(), Attacker);
		}
		else
		{
			UGameplayStatics::ApplyDamage(Target, MeleeDamage, Attacker->GetController(), Attacker, UDamageType::StaticClass());
		}
	}

	return true;
}
