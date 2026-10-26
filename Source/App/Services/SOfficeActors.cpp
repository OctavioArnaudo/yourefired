#include "SOfficeActors.h"

USOfficeActors::USOfficeActors()
	: IdentifierName(TEXT("SOfficeActors")), bIsActive(true)
{
}

bool USOfficeActors::ProcessSOfficeActors(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USOfficeActors] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
