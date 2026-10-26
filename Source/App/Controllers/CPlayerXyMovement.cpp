#include "CPlayerXyMovement.h"

UCPlayerXyMovement::UCPlayerXyMovement()
	: IdentifierName(TEXT("CPlayerXyMovement")), bIsActive(true)
{
}

bool UCPlayerXyMovement::ProcessCPlayerXyMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCPlayerXyMovement] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
