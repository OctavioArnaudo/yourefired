#include "IShoot.h"

UIShoot::UIShoot()
	: IdentifierName(TEXT("IShoot")), bIsActive(true)
{
}

bool UIShoot::ProcessIShoot(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIShoot] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
