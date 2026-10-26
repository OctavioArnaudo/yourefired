#include "IOfficeCubicles.h"

UIOfficeCubicles::UIOfficeCubicles()
	: IdentifierName(TEXT("IOfficeCubicles")), bIsActive(true)
{
}

bool UIOfficeCubicles::ProcessIOfficeCubicles(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIOfficeCubicles] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
