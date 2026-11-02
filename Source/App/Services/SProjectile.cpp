#include "SProjectile.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "App/Models/MProjectile.h"
#include "App/Models/MRange.h"
#include "App/Controllers/CProjectile.h"

SProjectile::SProjectile() {}

void SProjectile::SpawnProjectile(ACharacter* Character, const MProjectile& ProjectileModel, const MRange& RangeModel)
{
	if (!Character || !Character->GetWorld()) return;

	TSubclassOf<AActor> ClassToSpawn = ProjectileModel.ProjectileClass;
	if (!ClassToSpawn)
	{
		ClassToSpawn = ACProjectile::StaticClass();
	}

	FVector SpawnLocation = Character->GetActorLocation() + (Character->GetActorForwardVector() * RangeModel.RangedSpawnOffset);
	FRotator SpawnRotation = Character->GetActorRotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Owner = Character;
	SpawnParams.Instigator = Cast<APawn>(Character);

	AActor* SpawnedActor = Character->GetWorld()->SpawnActor<AActor>(ClassToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
	if (SpawnedActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("[SProjectile] Ranged mini-sphere projectile spawned successfully at %s!"), *SpawnLocation.ToString());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[SProjectile] Failed to spawn projectile!"));
	}
}
