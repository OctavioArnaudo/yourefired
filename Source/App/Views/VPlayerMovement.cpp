#include "VPlayerMovement.h"

UVPlayerMovement::UVPlayerMovement()
	: IdentifierName(TEXT("VPlayerMovement")), bIsActive(true)
{
}

bool UVPlayerMovement::ProcessVPlayerMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVPlayerMovement] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
