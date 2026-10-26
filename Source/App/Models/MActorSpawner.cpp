#include "MActorSpawner.h"

UMActorSpawner::UMActorSpawner()
	: IdentifierName(TEXT("MActorSpawner")), bIsActive(true)
{
}

bool UMActorSpawner::ProcessMActorSpawner(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMActorSpawner] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
