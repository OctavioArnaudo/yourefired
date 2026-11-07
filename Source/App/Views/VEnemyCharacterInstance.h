#pragma once
#include "CoreMinimal.h"

class ACharacter;
class UStaticMeshComponent;

class APP_API VEnemyCharacterInstance
{
public:
	VEnemyCharacterInstance();
	void SetupVisuals(ACharacter* CharacterOwner, UStaticMeshComponent*& OutMesh);
};
