#include "IPlayerXyzMovement.h"

UIPlayerXyzMovement::UIPlayerXyzMovement()
	: IdentifierName(TEXT("IPlayerXyzMovement")), bIsActive(true)
{
}

bool UIPlayerXyzMovement::ProcessIPlayerXyzMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIPlayerXyzMovement] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
