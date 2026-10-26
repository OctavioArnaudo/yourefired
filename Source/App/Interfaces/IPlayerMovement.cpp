#include "IPlayerMovement.h"

UIPlayerMovement::UIPlayerMovement()
	: IdentifierName(TEXT("IPlayerMovement")), bIsActive(true)
{
}

bool UIPlayerMovement::ProcessIPlayerMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIPlayerMovement] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
