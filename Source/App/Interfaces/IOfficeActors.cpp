#include "IOfficeActors.h"

UIOfficeActors::UIOfficeActors()
	: IdentifierName(TEXT("IOfficeActors")), bIsActive(true)
{
}

bool UIOfficeActors::ProcessIOfficeActors(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIOfficeActors] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
