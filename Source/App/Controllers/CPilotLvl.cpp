#include "CPilotLvl.h"

UCPilotLvl::UCPilotLvl()
	: IdentifierName(TEXT("CPilotLvl")), bIsActive(true)
{
}

bool UCPilotLvl::ProcessCPilotLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCPilotLvl] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
