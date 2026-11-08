#include "SPickupActorInstance.h"
#include "Engine/World.h"
#include "App/Controllers/CPickupActorInstance.h"

USPickupActorInstance::USPickupActorInstance()
	: IdentifierName(TEXT("SPickupActorInstance")), bIsActive(true)
{
}

AActor* USPickupActorInstance::SpawnHealthPickup(UWorld* World, const FVector& Location)
{
	if (!World) return nullptr;

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	ACPickupActorInstance* Pickup = World->SpawnActor<ACPickupActorInstance>(ACPickupActorInstance::StaticClass(), Location, FRotator::ZeroRotator, SpawnParams);
	if (Pickup)
	{
		UE_LOG(LogTemp, Warning, TEXT("[USPickupActorInstance] Spawned health pickup rhombus at %s"), *Location.ToString());
	}
	return Pickup;
}
