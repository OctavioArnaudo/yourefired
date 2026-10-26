#include "CSmSpawner.h"

UCSmSpawner::UCSmSpawner()
	: IdentifierName(TEXT("CSmSpawner")), bIsActive(true)
{
}

bool UCSmSpawner::ProcessCSmSpawner(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCSmSpawner] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
