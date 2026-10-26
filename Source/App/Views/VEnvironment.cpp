#include "VEnvironment.h"

UVEnvironment::UVEnvironment()
	: IdentifierName(TEXT("VEnvironment")), bIsActive(true)
{
}

bool UVEnvironment::ProcessVEnvironment(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVEnvironment] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
