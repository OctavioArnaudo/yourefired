#include "SEnvironment.h"

USEnvironment::USEnvironment()
	: IdentifierName(TEXT("SEnvironment")), bIsActive(true)
{
}

bool USEnvironment::ProcessSEnvironment(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USEnvironment] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
