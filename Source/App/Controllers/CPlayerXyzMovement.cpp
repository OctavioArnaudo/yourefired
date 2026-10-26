#include "CPlayerXyzMovement.h"

UCPlayerXyzMovement::UCPlayerXyzMovement()
	: IdentifierName(TEXT("CPlayerXyzMovement")), bIsActive(true)
{
}

bool UCPlayerXyzMovement::ProcessCPlayerXyzMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCPlayerXyzMovement] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
