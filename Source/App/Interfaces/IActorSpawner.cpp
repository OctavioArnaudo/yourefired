#include "IActorSpawner.h"

UIActorSpawner::UIActorSpawner()
	: IdentifierName(TEXT("IActorSpawner")), bIsActive(true)
{
}

bool UIActorSpawner::ProcessIActorSpawner(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIActorSpawner] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
