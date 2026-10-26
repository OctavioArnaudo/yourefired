#include "IWorldLvl.h"

UIWorldLvl::UIWorldLvl()
	: IdentifierName(TEXT("IWorldLvl")), bIsActive(true)
{
}

bool UIWorldLvl::ProcessIWorldLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIWorldLvl] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
