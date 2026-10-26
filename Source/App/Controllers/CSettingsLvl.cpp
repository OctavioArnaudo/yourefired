#include "CSettingsLvl.h"

UCSettingsLvl::UCSettingsLvl()
	: IdentifierName(TEXT("CSettingsLvl")), bIsActive(true)
{
}

bool UCSettingsLvl::ProcessCSettingsLvl(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCSettingsLvl] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
