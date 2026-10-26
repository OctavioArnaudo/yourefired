#include "IAiPatrol.h"

UIAiPatrol::UIAiPatrol()
	: IdentifierName(TEXT("IAiPatrol")), bIsActive(true)
{
}

bool UIAiPatrol::ProcessIAiPatrol(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIAiPatrol] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
