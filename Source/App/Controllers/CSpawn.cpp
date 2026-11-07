#include "CSpawn.h"

CSpawn::CSpawn()
{
}

bool CSpawn::ProcessSpawnRequest(const MSpawn& SpawnModel)
{
	UE_LOG(LogTemp, Log, TEXT("[CSpawn] Processing spawn request for %s at %s"), *SpawnModel.ActorClassPath, *SpawnModel.SpawnLocation.ToString());
	return true;
}
