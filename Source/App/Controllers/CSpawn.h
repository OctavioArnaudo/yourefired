#pragma once

#include "CoreMinimal.h"
#include "App/Models/MSpawn.h"

class APP_API CSpawn
{
public:
	CSpawn();

	bool ProcessSpawnRequest(const MSpawn& SpawnModel);
};
