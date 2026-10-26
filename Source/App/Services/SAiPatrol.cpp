#include "SAiPatrol.h"

USAiPatrol::USAiPatrol()
	: IdentifierName(TEXT("SAiPatrol")), bIsActive(true)
{
}

bool USAiPatrol::ProcessSAiPatrol(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USAiPatrol] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
