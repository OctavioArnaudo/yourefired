#include "MOfficeActors.h"

UMOfficeActors::UMOfficeActors()
	: IdentifierName(TEXT("MOfficeActors")), bIsActive(true)
{
}

bool UMOfficeActors::ProcessMOfficeActors(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMOfficeActors] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
