#include "SProjectile.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "App/Models/MProjectile.h"
#include "App/Models/MRange.h"

SProjectile::SProjectile() {}

void SProjectile::SpawnProjectile(ACharacter* Character, const MProjectile& ProjectileModel, const MRange& RangeModel)
{
	if (!Character) return;
	if (!ProjectileModel.ProjectileClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("[SProjectile] No ProjectileClass assigned!"));
		return;
	}

	FVector SpawnLocation = Character->GetActorLocation() + (Character->GetActorForwardVector() * RangeModel.RangedSpawnOffset);
	FRotator SpawnRotation = Character->GetActorRotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	SpawnParams.Owner = Character;
	SpawnParams.Instigator = Cast<APawn>(Character);

	AActor* SpawnedActor = Character->GetWorld()->SpawnActor<AActor>(ProjectileModel.ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
	if (SpawnedActor)
	{
		UE_LOG(LogTemp, Log, TEXT("[SProjectile] Ranged projectile spawned successfully!"));
	}
}
