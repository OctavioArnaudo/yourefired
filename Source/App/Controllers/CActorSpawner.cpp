#include "CActorSpawner.h"

UCActorSpawner::UCActorSpawner()
	: IdentifierName(TEXT("CActorSpawner")), bIsActive(true)
{
}

bool UCActorSpawner::ProcessCActorSpawner(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCActorSpawner] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
