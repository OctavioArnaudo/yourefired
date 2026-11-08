#pragma once

#include "CoreMinimal.h"

class APP_API VPickupActorInstance
{
public:
	VPickupActorInstance();

	void SetupVisuals(class AActor* OwnerActor, UStaticMeshComponent* MeshComp);
};
