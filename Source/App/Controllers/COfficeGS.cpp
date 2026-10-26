#include "COfficeGs.h"

UCOfficeGs::UCOfficeGs()
	: IdentifierName(TEXT("COfficeGs")), bIsActive(true)
{
}

bool UCOfficeGs::ProcessCOfficeGs(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCOfficeGs] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
