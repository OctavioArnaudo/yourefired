#include "SShoot.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "App/Controllers/CProjectile.h"

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
	if (!Shooter || !Shooter->GetWorld()) return false;

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

	AActor* SpawnedProjectile = Shooter->GetWorld()->SpawnActor<AActor>(ClassToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
	if (SpawnedProjectile)
	{
		UE_LOG(LogTemp, Log, TEXT("[USShoot] Unit RANGED shoot executed! Spawned projectile '%s' at %s."),
			*SpawnedProjectile->GetName(), *SpawnLocation.ToString());
		return true;
	}

	return false;
}

bool USShoot::PerformDiscreteRangedShoot(ACharacter* Shooter, UMShoot* ShootModel, TSubclassOf<AActor> ProjectileClass, float CurrentTime)
{
	if (!Shooter || !Shooter->GetWorld() || !ShootModel) return false;

	// Check if enough time has elapsed according to ShootModel's FireRate
	if (!ShootModel->CanFire(CurrentTime))
	{
		return false; // Cooldown not met yet; do not spawn
	}

	// Update last fire time to enforce discrete rate limiting
	ShootModel->LastFireTime = CurrentTime;

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

	AActor* SpawnedProjectile = Shooter->GetWorld()->SpawnActor<AActor>(ClassToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
	if (SpawnedProjectile)
	{
		UE_LOG(LogTemp, Log, TEXT("[USShoot] DISCRETE projectile spawned for '%s' at t=%.2fs! Next shot available in %.2fs."),
			*Shooter->GetName(), CurrentTime, ShootModel->FireRate);
		return true;
	}

	return false;
}
