#include "SPlayerXyMovement.h"

USPlayerXyMovement::USPlayerXyMovement()
	: IdentifierName(TEXT("SPlayerXyMovement")), bIsActive(true)
{
}

bool USPlayerXyMovement::ProcessSPlayerXyMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USPlayerXyMovement] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
