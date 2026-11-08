#include "SShoot.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "App/Controllers/CProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

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
	if (!IsValid(Shooter) || !Shooter->GetWorld()) return false;

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

	AActor* SpawnedActor = Shooter->GetWorld()->SpawnActor<AActor>(ClassToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
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

		UE_LOG(LogTemp, Log, TEXT("[USShoot] Unit RANGED shoot executed! Spawned projectile '%s' at %s with active velocity."),
			*SpawnedActor->GetName(), *SpawnLocation.ToString());
		return true;
	}

	return false;
}

bool USShoot::PerformDiscreteRangedShoot(ACharacter* Shooter, UMShoot* ShootModel, TSubclassOf<AActor> ProjectileClass, float CurrentTime)
{
	if (!IsValid(Shooter) || !Shooter->GetWorld() || !ShootModel) return false;

	if (!ShootModel->CanFire(CurrentTime))
	{
		return false;
	}

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

	AActor* SpawnedActor = Shooter->GetWorld()->SpawnActor<AActor>(ClassToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
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

		UE_LOG(LogTemp, Log, TEXT("[USShoot] DISCRETE projectile spawned for '%s' at t=%.2fs with active velocity."),
			*Shooter->GetName(), CurrentTime);
		return true;
	}

	return false;
}
