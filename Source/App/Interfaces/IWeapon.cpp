#include "IWeapon.h"

UIWeapon::UIWeapon()
	: IdentifierName(TEXT("IWeapon")), bIsActive(true)
{
}

bool UIWeapon::ProcessIWeapon(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIWeapon] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
