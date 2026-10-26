#include "IOfficeGm.h"

UIOfficeGm::UIOfficeGm()
	: IdentifierName(TEXT("IOfficeGm")), bIsActive(true)
{
}

bool UIOfficeGm::ProcessIOfficeGm(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIOfficeGm] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
