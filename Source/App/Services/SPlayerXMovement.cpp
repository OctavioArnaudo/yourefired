#include "SPlayerXMovement.h"

USPlayerXMovement::USPlayerXMovement()
	: IdentifierName(TEXT("SPlayerXMovement")), bIsActive(true)
{
}

bool USPlayerXMovement::ProcessSPlayerXMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USPlayerXMovement] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
