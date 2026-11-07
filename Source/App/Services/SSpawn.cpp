#include "SSpawn.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

SSpawn::SSpawn()
{
}

AActor* SSpawn::SpawnActor(UWorld* World, UClass* ActorClass, const FVector& Location, const FRotator& Rotation)
{
	if (!World || !ActorClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("[SSpawn] World or ActorClass is null!"));
		return nullptr;
	}

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AActor* SpawnedActor = World->SpawnActor<AActor>(ActorClass, Location, Rotation, SpawnParams);
	if (SpawnedActor)
	{
		UE_LOG(LogTemp, Log, TEXT("[SSpawn] Successfully spawned actor: %s"), *SpawnedActor->GetName());
	}
	return SpawnedActor;
}
