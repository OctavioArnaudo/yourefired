#include "COfficeActors.h"

UCOfficeActors::UCOfficeActors()
	: IdentifierName(TEXT("COfficeActors")), bIsActive(true)
{
}

bool UCOfficeActors::ProcessCOfficeActors(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCOfficeActors] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
