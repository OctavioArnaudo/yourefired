#pragma once

#include "CoreMinimal.h"

class UWorld;
class AActor;

class APP_API SSpawn
{
public:
	SSpawn();

	AActor* SpawnActor(UWorld* World, UClass* ActorClass, const FVector& Location, const FRotator& Rotation);
};
