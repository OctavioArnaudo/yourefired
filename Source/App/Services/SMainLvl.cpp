#include "SMainLvl.h"

USMainLvl::USMainLvl()
	: IdentifierName(TEXT("SMainLvl")), bIsActive(true)
{
}

bool USMainLvl::ProcessSMainLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USMainLvl] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
