#include "VPlayerXyzMovement.h"

UVPlayerXyzMovement::UVPlayerXyzMovement()
	: IdentifierName(TEXT("VPlayerXyzMovement")), bIsActive(true)
{
}

bool UVPlayerXyzMovement::ProcessVPlayerXyzMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVPlayerXyzMovement] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
