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
