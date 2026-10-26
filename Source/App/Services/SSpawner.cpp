#include "SSpawner.h"

USSpawner::USSpawner()
	: IdentifierName(TEXT("SSpawner")), bIsActive(true)
{
}

bool USSpawner::ProcessSSpawner(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USSpawner] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
