#include "SPlayerMovement.h"

USPlayerMovement::USPlayerMovement()
	: IdentifierName(TEXT("SPlayerMovement")), bIsActive(true)
{
}

bool USPlayerMovement::ProcessSPlayerMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USPlayerMovement] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
