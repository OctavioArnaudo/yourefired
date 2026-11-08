#include "SMelee.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/DamageEvents.h"
#include "App/Services/SDamage.h"
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
		if (Dist <= 300.0f)
		{
			UE_LOG(LogTemp, Warning, TEXT("[USMelee] Enemy melee hit Player at dist %.1f!"), Dist);
			PerformMeleeAttackOnTarget(Attacker, PlayerPawn);
			return true;
		}
	}

	// 2. If attacker is player, check distance to all characters (enemies) safely
	TArray<AActor*> AllCharacters;
	UGameplayStatics::GetAllActorsOfClass(World, ACharacter::StaticClass(), AllCharacters);
	UE_LOG(LogTemp, Warning, TEXT("[USMelee] Player performed melee attack. Scanning %d characters in world."), AllCharacters.Num());

	for (AActor* Actor : AllCharacters)
	{
		if (IsValid(Actor) && Actor != Attacker && Actor != PlayerPawn)
		{
			float Dist = FVector::Dist(AttackerLoc, Actor->GetActorLocation());
			UE_LOG(LogTemp, Warning, TEXT("[USMelee] Scanning character '%s' at dist %.1f"), *Actor->GetName(), Dist);

			if (Dist <= 300.0f)
			{
				UE_LOG(LogTemp, Warning, TEXT("[USMelee] Player melee hit Target '%s' at dist %.1f!"), *Actor->GetName(), Dist);
				PerformMeleeAttackOnTarget(Attacker, Actor);
				break;
			}
		}
	}

	return true;
}

bool USMelee::PerformMeleeAttackOnTarget(ACharacter* Attacker, AActor* Target)
{
	if (!IsValid(Attacker) || !IsValid(Target)) return false;
	USDamage::ApplyDamageUniversal(Target, MeleeDamage, Attacker->GetController(), Attacker);
	return true;
}
