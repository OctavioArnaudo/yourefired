#include "VWeapon.h"

UVWeapon::UVWeapon()
	: IdentifierName(TEXT("VWeapon")), bIsActive(true)
{
}

bool UVWeapon::ProcessVWeapon(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVWeapon] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
