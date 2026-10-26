#include "VOfficeActors.h"

UVOfficeActors::UVOfficeActors()
	: IdentifierName(TEXT("VOfficeActors")), bIsActive(true)
{
}

bool UVOfficeActors::ProcessVOfficeActors(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVOfficeActors] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
