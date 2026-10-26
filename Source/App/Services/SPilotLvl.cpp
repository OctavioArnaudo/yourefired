#include "SPilotLvl.h"

USPilotLvl::USPilotLvl()
	: IdentifierName(TEXT("SPilotLvl")), bIsActive(true)
{
}

bool USPilotLvl::ProcessSPilotLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USPilotLvl] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
