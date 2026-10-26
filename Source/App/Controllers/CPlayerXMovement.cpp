#include "CPlayerXMovement.h"

UCPlayerXMovement::UCPlayerXMovement()
	: IdentifierName(TEXT("CPlayerXMovement")), bIsActive(true)
{
}

bool UCPlayerXMovement::ProcessCPlayerXMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCPlayerXMovement] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
