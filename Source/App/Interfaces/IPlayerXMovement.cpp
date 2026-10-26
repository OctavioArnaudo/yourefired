#include "IPlayerXMovement.h"

UIPlayerXMovement::UIPlayerXMovement()
	: IdentifierName(TEXT("IPlayerXMovement")), bIsActive(true)
{
}

bool UIPlayerXMovement::ProcessIPlayerXMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIPlayerXMovement] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
