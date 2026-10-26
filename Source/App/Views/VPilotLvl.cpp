#include "VPilotLvl.h"

UVPilotLvl::UVPilotLvl()
	: IdentifierName(TEXT("VPilotLvl")), bIsActive(true)
{
}

bool UVPilotLvl::ProcessVPilotLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVPilotLvl] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
