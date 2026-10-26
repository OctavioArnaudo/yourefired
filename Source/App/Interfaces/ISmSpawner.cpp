#include "ISmSpawner.h"

UISmSpawner::UISmSpawner()
	: IdentifierName(TEXT("ISmSpawner")), bIsActive(true)
{
}

bool UISmSpawner::ProcessISmSpawner(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UISmSpawner] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
