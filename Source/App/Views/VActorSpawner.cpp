#include "VActorSpawner.h"

UVActorSpawner::UVActorSpawner()
	: IdentifierName(TEXT("VActorSpawner")), bIsActive(true)
{
}

bool UVActorSpawner::ProcessVActorSpawner(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVActorSpawner] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
