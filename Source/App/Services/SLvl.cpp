#include "SLvl.h"

USLvl::USLvl()
	: IdentifierName(TEXT("SLvl")), bIsActive(true)
{
}

bool USLvl::ProcessSLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USLvl] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
