#include "IPatrol.h"

UIPatrol::UIPatrol()
	: IdentifierName(TEXT("IPatrol")), bIsActive(true)
{
}

bool UIPatrol::ProcessIPatrol(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIPatrol] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
