#pragma once

#include "CoreMinimal.h"

class APP_API MSpawn
{
public:
	MSpawn();

	FVector SpawnLocation;
	FRotator SpawnRotation;
	FVector SpawnScale;
	FString ActorClassPath;

	FTransform GetSpawnTransform() const;
};
