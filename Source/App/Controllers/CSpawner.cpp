#include "CSpawner.h"

UCSpawner::UCSpawner()
	: IdentifierName(TEXT("CSpawner")), bIsActive(true)
{
}

bool UCSpawner::ProcessCSpawner(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCSpawner] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
