#include "VPickupActorInstance.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"

VPickupActorInstance::VPickupActorInstance()
{
}

void VPickupActorInstance::SetupVisuals(AActor* OwnerActor, UStaticMeshComponent* MeshComp)
{
	if (OwnerActor && MeshComp)
	{
		UE_LOG(LogTemp, Log, TEXT("[VPickupActorInstance] Visuals setup for health pickup rhombus."));
	}
}
