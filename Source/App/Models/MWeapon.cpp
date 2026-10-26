#include "MWeapon.h"

UMWeapon::UMWeapon()
	: IdentifierName(TEXT("MWeapon")), bIsActive(true)
{
}

bool UMWeapon::ProcessMWeapon(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMWeapon] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
