#include "VPlayerXyMovement.h"

UVPlayerXyMovement::UVPlayerXyMovement()
	: IdentifierName(TEXT("VPlayerXyMovement")), bIsActive(true)
{
}

bool UVPlayerXyMovement::ProcessVPlayerXyMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVPlayerXyMovement] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
