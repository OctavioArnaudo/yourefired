#include "SWeapon.h"

USWeapon::USWeapon()
	: IdentifierName(TEXT("SWeapon")), bIsActive(true)
{
}

bool USWeapon::ProcessSWeapon(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USWeapon] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
