#include "MSmSpawner.h"

UMSmSpawner::UMSmSpawner()
	: IdentifierName(TEXT("MSmSpawner")), bIsActive(true)
{
}

bool UMSmSpawner::ProcessMSmSpawner(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMSmSpawner] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
