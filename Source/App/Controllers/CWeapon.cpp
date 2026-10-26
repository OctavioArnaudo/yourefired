#include "CWeapon.h"

UCWeapon::UCWeapon()
	: IdentifierName(TEXT("CWeapon")), bIsActive(true)
{
}

bool UCWeapon::ProcessCWeapon(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCWeapon] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
