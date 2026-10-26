#include "CPlayerMovement.h"

UCPlayerMovement::UCPlayerMovement()
	: IdentifierName(TEXT("CPlayerMovement")), bIsActive(true)
{
}

bool UCPlayerMovement::ProcessCPlayerMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCPlayerMovement] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
