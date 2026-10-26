#include "SSmSpawner.h"

USSmSpawner::USSmSpawner()
	: IdentifierName(TEXT("SSmSpawner")), bIsActive(true)
{
}

bool USSmSpawner::ProcessSSmSpawner(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USSmSpawner] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
