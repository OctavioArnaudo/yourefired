#include "SActorSpawner.h"

USActorSpawner::USActorSpawner()
	: IdentifierName(TEXT("SActorSpawner")), bIsActive(true)
{
}

bool USActorSpawner::ProcessSActorSpawner(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USActorSpawner] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
