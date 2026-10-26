#include "IPlayerXyMovement.h"

UIPlayerXyMovement::UIPlayerXyMovement()
	: IdentifierName(TEXT("IPlayerXyMovement")), bIsActive(true)
{
}

bool UIPlayerXyMovement::ProcessIPlayerXyMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIPlayerXyMovement] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
