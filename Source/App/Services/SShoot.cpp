#include "SShoot.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "App/Controllers/CProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
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

	// 1. Spawn visual projectile for graphics/animation feedback
	TSubclassOf<AActor> ClassToSpawn = ProjectileClass;
	if (!ClassToSpawn)
	{
		ClassToSpawn = ACProjectile::StaticClass();
	}

	FVector SpawnLocation = Shooter->GetActorLocation() + (Shooter->GetActorForwardVector() * 100.0f);
	FRotator SpawnRotation = Shooter->GetActorRotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Owner = Shooter;
	SpawnParams.Instigator = Shooter;

	AActor* SpawnedActor = World->SpawnActor<AActor>(ClassToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
	if (IsValid(SpawnedActor))
	{
		ACProjectile* Proj = Cast<ACProjectile>(SpawnedActor);
		if (IsValid(Proj))
		{
			Proj->ShooterActor = Shooter;
			Proj->SetActorRotation(SpawnRotation);
			if (Proj->ProjectileMovement)
			{
				Proj->ProjectileMovement->SetUpdatedComponent(Proj->GetRootComponent());
				Proj->ProjectileMovement->Velocity = SpawnRotation.Vector() * Proj->ProjectileMovement->InitialSpeed;
				Proj->ProjectileMovement->Activate();
			}
		}
	}

	// 2. Instant trace-based damage application for 100% reliable combat hit
	FVector StartLoc = Shooter->GetActorLocation() + (Shooter->GetActorForwardVector() * 50.0f);
	FVector EndLoc = StartLoc + (Shooter->GetActorForwardVector() * 2000.0f);

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
		UE_LOG(LogTemp, Warning, TEXT("[USShoot] Ranged visual+instant hit on '%s'! Applying damage."), *HitActor->GetName());

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

	// 1. Spawn visual projectile for graphics feedback
	TSubclassOf<AActor> ClassToSpawn = ProjectileClass ? ProjectileClass : ShootModel->ProjectileClass;
	if (!ClassToSpawn)
	{
		ClassToSpawn = ACProjectile::StaticClass();
	}

	FVector SpawnLocation = Shooter->GetActorLocation() + (Shooter->GetActorForwardVector() * 100.0f);
	FRotator SpawnRotation = Shooter->GetActorRotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Owner = Shooter;
	SpawnParams.Instigator = Shooter;

	AActor* SpawnedActor = World->SpawnActor<AActor>(ClassToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
	if (IsValid(SpawnedActor))
	{
		ACProjectile* Proj = Cast<ACProjectile>(SpawnedActor);
		if (IsValid(Proj))
		{
			Proj->ShooterActor = Shooter;
			Proj->SetActorRotation(SpawnRotation);
			if (Proj->ProjectileMovement)
			{
				Proj->ProjectileMovement->SetUpdatedComponent(Proj->GetRootComponent());
				Proj->ProjectileMovement->Velocity = SpawnRotation.Vector() * Proj->ProjectileMovement->InitialSpeed;
				Proj->ProjectileMovement->Activate();
			}
		}
	}

	// 2. Instant trace-based damage application for 100% reliable combat hit
	FVector StartLoc = Shooter->GetActorLocation() + (Shooter->GetActorForwardVector() * 50.0f);
	FVector EndLoc = StartLoc + (Shooter->GetActorForwardVector() * 2000.0f);

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
		UE_LOG(LogTemp, Warning, TEXT("[USShoot] Discrete ranged visual+instant hit on '%s'! Applying damage."), *HitActor->GetName());

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
