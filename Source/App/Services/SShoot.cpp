#include "SShoot.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "App/Controllers/CPlayerCharacterInstance.h"
#include "App/Controllers/CEnemyCharacterInstance.h"

USShoot::USShoot()
	: IdentifierName(TEXT("SShoot")), bIsActive(true)
{
}

bool USShoot::ProcessSShoot(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USShoot] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}

bool USShoot::PerformRangedShoot(ACharacter* Shooter, TSubclassOf<AActor> ProjectileClass)
{
	if (!IsValid(Shooter) || !IsValid(Shooter->GetWorld())) return false;

	UWorld* World = Shooter->GetWorld();
	FVector StartLoc = Shooter->GetActorLocation() + (Shooter->GetActorForwardVector() * 50.0f);
	FVector EndLoc = StartLoc + (Shooter->GetActorForwardVector() * 2000.0f);

	UE_LOG(LogTemp, Warning, TEXT("[USShoot] '%s' performs ranged shoot (Trace-based)."), *Shooter->GetName());

	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(Shooter);

	bool bHit = World->LineTraceSingleByChannel(
		HitResult,
		StartLoc,
		EndLoc,
		ECC_Pawn,
		QueryParams
	);

	if (bHit && IsValid(HitResult.GetActor()))
	{
		AActor* HitActor = HitResult.GetActor();
		UE_LOG(LogTemp, Warning, TEXT("[USShoot] Ranged hit target '%s' (Class: %s)! Applying damage."), *HitActor->GetName(), *HitActor->GetClass()->GetName());

		ACPlayerCharacterInstance* PlayerTarget = Cast<ACPlayerCharacterInstance>(HitActor);
		if (IsValid(PlayerTarget))
		{
			PlayerTarget->ReceiveDamageDirect(25.0f);
		}
		else
		{
			ACEnemyCharacterInstance* EnemyTarget = Cast<ACEnemyCharacterInstance>(HitActor);
			if (IsValid(EnemyTarget))
			{
				EnemyTarget->ReceiveDamageDirect(25.0f);
			}
			else
			{
				UGameplayStatics::ApplyDamage(HitActor, 25.0f, Shooter->GetController(), Shooter, UDamageType::StaticClass());
			}
		}
	}

	return true;
}

bool USShoot::PerformDiscreteRangedShoot(ACharacter* Shooter, UMShoot* ShootModel, TSubclassOf<AActor> ProjectileClass, float CurrentTime)
{
	if (!IsValid(Shooter) || !IsValid(Shooter->GetWorld()) || !ShootModel) return false;

	if (!ShootModel->CanFire(CurrentTime))
	{
		return false;
	}

	ShootModel->LastFireTime = CurrentTime;

	UWorld* World = Shooter->GetWorld();
	FVector StartLoc = Shooter->GetActorLocation() + (Shooter->GetActorForwardVector() * 50.0f);
	FVector EndLoc = StartLoc + (Shooter->GetActorForwardVector() * 2000.0f);

	UE_LOG(LogTemp, Warning, TEXT("[USShoot] '%s' performs discrete ranged shoot (Trace-based) at t=%.2fs."), *Shooter->GetName(), CurrentTime);

	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(Shooter);

	bool bHit = World->LineTraceSingleByChannel(
		HitResult,
		StartLoc,
		EndLoc,
		ECC_Pawn,
		QueryParams
	);

	if (bHit && IsValid(HitResult.GetActor()))
	{
		AActor* HitActor = HitResult.GetActor();
		UE_LOG(LogTemp, Warning, TEXT("[USShoot] Discrete ranged hit target '%s' (Class: %s)! Applying damage."), *HitActor->GetName(), *HitActor->GetClass()->GetName());

		ACPlayerCharacterInstance* PlayerTarget = Cast<ACPlayerCharacterInstance>(HitActor);
		if (IsValid(PlayerTarget))
		{
			PlayerTarget->ReceiveDamageDirect(25.0f);
		}
		else
		{
			ACEnemyCharacterInstance* EnemyTarget = Cast<ACEnemyCharacterInstance>(HitActor);
			if (IsValid(EnemyTarget))
			{
				EnemyTarget->ReceiveDamageDirect(25.0f);
			}
			else
			{
				UGameplayStatics::ApplyDamage(HitActor, 25.0f, Shooter->GetController(), Shooter, UDamageType::StaticClass());
			}
		}
	}

	return true;
}
