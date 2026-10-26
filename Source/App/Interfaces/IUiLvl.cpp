#include "IUiLvl.h"

UIUiLvl::UIUiLvl()
	: IdentifierName(TEXT("IUiLvl")), bIsActive(true)
{
}

bool UIUiLvl::ProcessIUiLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIUiLvl] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
