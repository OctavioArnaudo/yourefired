#include "MSpawner.h"

UMSpawner::UMSpawner()
	: IdentifierName(TEXT("MSpawner")), bIsActive(true)
{
}

bool UMSpawner::ProcessMSpawner(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMSpawner] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
