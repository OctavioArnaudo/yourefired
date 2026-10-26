#include "SGm.h"

USGm::USGm()
	: IdentifierName(TEXT("SGm")), bIsActive(true)
{
}

bool USGm::ProcessSGm(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USGm] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
