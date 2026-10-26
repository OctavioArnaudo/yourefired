#include "VSmSpawner.h"

UVSmSpawner::UVSmSpawner()
	: IdentifierName(TEXT("VSmSpawner")), bIsActive(true)
{
}

bool UVSmSpawner::ProcessVSmSpawner(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVSmSpawner] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
