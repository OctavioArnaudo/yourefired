#include "VPlayerXMovement.h"

UVPlayerXMovement::UVPlayerXMovement()
	: IdentifierName(TEXT("VPlayerXMovement")), bIsActive(true)
{
}

bool UVPlayerXMovement::ProcessVPlayerXMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVPlayerXMovement] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
