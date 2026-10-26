#include "VOfficeCubicles.h"

UVOfficeCubicles::UVOfficeCubicles()
	: IdentifierName(TEXT("VOfficeCubicles")), bIsActive(true)
{
}

bool UVOfficeCubicles::ProcessVOfficeCubicles(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVOfficeCubicles] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
