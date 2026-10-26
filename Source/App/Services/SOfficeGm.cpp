#include "SOfficeGm.h"

USOfficeGm::USOfficeGm()
	: IdentifierName(TEXT("SOfficeGm")), bIsActive(true)
{
}

bool USOfficeGm::ProcessSOfficeGm(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USOfficeGm] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
