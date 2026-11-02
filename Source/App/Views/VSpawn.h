#pragma once
#include "CoreMinimal.h"

class ACharacter;
class UStaticMeshComponent;

class APP_API VSpawn
{
public:
	VSpawn();
	void BuildPlayerMesh(ACharacter* Owner, UStaticMeshComponent*& OutMesh);
};
