#include "CEnvironment.h"

UCEnvironment::UCEnvironment()
	: IdentifierName(TEXT("CEnvironment")), bIsActive(true)
{
}

bool UCEnvironment::ProcessCEnvironment(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCEnvironment] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
