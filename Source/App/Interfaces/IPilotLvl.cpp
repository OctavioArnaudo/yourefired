#include "IPilotLvl.h"

UIPilotLvl::UIPilotLvl()
	: IdentifierName(TEXT("IPilotLvl")), bIsActive(true)
{
}

bool UIPilotLvl::ProcessIPilotLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIPilotLvl] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
