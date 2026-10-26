#include "MOfficeCubicles.h"

UMOfficeCubicles::UMOfficeCubicles()
	: IdentifierName(TEXT("MOfficeCubicles")), bIsActive(true)
{
}

bool UMOfficeCubicles::ProcessMOfficeCubicles(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMOfficeCubicles] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
