#include "MSettingsLvl.h"

UMSettingsLvl::UMSettingsLvl()
	: IdentifierName(TEXT("MSettingsLvl")), bIsActive(true)
{
}

bool UMSettingsLvl::ProcessMSettingsLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMSettingsLvl] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
