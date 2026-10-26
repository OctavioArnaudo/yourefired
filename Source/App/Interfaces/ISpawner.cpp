#include "ISpawner.h"

UISpawner::UISpawner()
	: IdentifierName(TEXT("ISpawner")), bIsActive(true)
{
}

bool UISpawner::ProcessISpawner(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UISpawner] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
