#include "COfficeGm.h"

UCOfficeGm::UCOfficeGm()
	: IdentifierName(TEXT("COfficeGm")), bIsActive(true)
{
}

bool UCOfficeGm::ProcessCOfficeGm(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCOfficeGm] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
