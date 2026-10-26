#include "VSpawner.h"

UVSpawner::UVSpawner()
	: IdentifierName(TEXT("VSpawner")), bIsActive(true)
{
}

bool UVSpawner::ProcessVSpawner(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVSpawner] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
