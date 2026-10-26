#include "ISettingsLvl.h"

UISettingsLvl::UISettingsLvl()
	: IdentifierName(TEXT("ISettingsLvl")), bIsActive(true)
{
}

bool UISettingsLvl::ProcessISettingsLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UISettingsLvl] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
