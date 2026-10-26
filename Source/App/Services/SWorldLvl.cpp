#include "SWorldLvl.h"

USWorldLvl::USWorldLvl()
	: IdentifierName(TEXT("SWorldLvl")), bIsActive(true)
{
}

bool USWorldLvl::ProcessSWorldLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USWorldLvl] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
