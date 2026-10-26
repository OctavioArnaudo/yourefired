#include "IDefeatLvl.h"

UIDefeatLvl::UIDefeatLvl()
	: IdentifierName(TEXT("IDefeatLvl")), bIsActive(true)
{
}

bool UIDefeatLvl::ProcessIDefeatLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIDefeatLvl] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
