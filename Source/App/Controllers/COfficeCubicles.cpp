#include "COfficeCubicles.h"

UCOfficeCubicles::UCOfficeCubicles()
	: IdentifierName(TEXT("COfficeCubicles")), bIsActive(true)
{
}

bool UCOfficeCubicles::ProcessCOfficeCubicles(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCOfficeCubicles] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
