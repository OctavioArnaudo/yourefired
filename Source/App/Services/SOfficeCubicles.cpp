#include "SOfficeCubicles.h"

USOfficeCubicles::USOfficeCubicles()
	: IdentifierName(TEXT("SOfficeCubicles")), bIsActive(true)
{
}

bool USOfficeCubicles::ProcessSOfficeCubicles(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USOfficeCubicles] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
