#include "MSpawn.h"

MSpawn::MSpawn()
	: SpawnLocation(0.0f, 0.0f, 100.0f)
	, SpawnRotation(0.0f, 0.0f, 0.0f)
	, SpawnScale(1.0f, 1.0f, 1.0f)
	, ActorClassPath(TEXT("/Game/Blueprints/BP_DefaultActor"))
{
}

FTransform MSpawn::GetSpawnTransform() const
{
	return FTransform(SpawnRotation, SpawnLocation, SpawnScale);
}
