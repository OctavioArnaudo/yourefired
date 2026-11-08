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

static void ApplyDamageUniversal(AActor* Target, float DamageAmount, AController* EventInstigator, AActor* DamageCauser)
{
	if (!IsValid(Target)) return;

	UE_LOG(LogTemp, Warning, TEXT("[UniversalDamage] Applying %.2f damage to target '%s' (Class: %s)"),
		DamageAmount, *Target->GetName(), *Target->GetClass()->GetName());

	// 1. Try reflection-based call to ReceiveDamageDirect (works on any C++ or Blueprint class with ReceiveDamageDirect)
	UFunction* Func = Target->FindFunction(FName("ReceiveDamageDirect"));
	if (Func)
	{
		struct FParams {
			float Amount;
		};
		FParams Parms;
		Parms.Amount = DamageAmount;

		Target->ProcessEvent(Func, &Parms);
		UE_LOG(LogTemp, Warning, TEXT("[UniversalDamage] Successfully invoked ReceiveDamageDirect via reflection on '%s'."), *Target->GetName());
		return;
	}

	// 2. Direct C++ cast fallbacks
	ACPlayerCharacterInstance* PlayerTarget = Cast<ACPlayerCharacterInstance>(Target);
	if (IsValid(PlayerTarget))
	{
		PlayerTarget->ReceiveDamageDirect(DamageAmount);
		return;
	}

	ACEnemyCharacterInstance* EnemyTarget = Cast<ACEnemyCharacterInstance>(Target);
	if (IsValid(EnemyTarget))
	{
		EnemyTarget->ReceiveDamageDirect(DamageAmount);
		return;
	}

	// 3. GameplayStatics fallback
	UGameplayStatics::ApplyDamage(Target, DamageAmount, EventInstigator, DamageCauser, UDamageType::StaticClass());
	UE_LOG(LogTemp, Warning, TEXT("[UniversalDamage] Invoked ApplyDamage fallback on '%s'."), *Target->GetName());
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
	ApplyDamageUniversal(Target, MeleeDamage, Attacker->GetController(), Attacker);
	return true;
}
