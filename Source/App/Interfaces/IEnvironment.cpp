#include "IEnvironment.h"

UIEnvironment::UIEnvironment()
	: IdentifierName(TEXT("IEnvironment")), bIsActive(true)
{
}

bool UIEnvironment::ProcessIEnvironment(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIEnvironment] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
