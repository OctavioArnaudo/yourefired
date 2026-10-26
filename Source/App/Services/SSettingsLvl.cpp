#include "SSettingsLvl.h"

USSettingsLvl::USSettingsLvl()
	: IdentifierName(TEXT("SSettingsLvl")), bIsActive(true)
{
}

bool USSettingsLvl::ProcessSSettingsLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USSettingsLvl] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
