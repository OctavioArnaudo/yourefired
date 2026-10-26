#include "SUiLvl.h"

USUiLvl::USUiLvl()
	: IdentifierName(TEXT("SUiLvl")), bIsActive(true)
{
}

bool USUiLvl::ProcessSUiLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USUiLvl] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
