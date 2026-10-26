#include "MPilotLvl.h"

UMPilotLvl::UMPilotLvl()
	: IdentifierName(TEXT("MPilotLvl")), bIsActive(true)
{
}

bool UMPilotLvl::ProcessMPilotLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMPilotLvl] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
