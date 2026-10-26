#include "SPlayerXyzMovement.h"

USPlayerXyzMovement::USPlayerXyzMovement()
	: IdentifierName(TEXT("SPlayerXyzMovement")), bIsActive(true)
{
}

bool USPlayerXyzMovement::ProcessSPlayerXyzMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USPlayerXyzMovement] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
