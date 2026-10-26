#include "VSettingsLvl.h"

UVSettingsLvl::UVSettingsLvl()
	: IdentifierName(TEXT("VSettingsLvl")), bIsActive(true)
{
}

bool UVSettingsLvl::ProcessVSettingsLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVSettingsLvl] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
