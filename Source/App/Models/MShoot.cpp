#include "MShoot.h"

UMShoot::UMShoot()
	: IdentifierName(TEXT("MShoot"))
	, bIsActive(true)
	, bIsFiring(false)
	, ProjectileSpeed(1000.0f)
	, FireRate(0.25f)
	, LastFireTime(0.0f)
	, ProjectileClass(nullptr)
{
}

bool UMShoot::CanFire(float CurrentTime) const
{
	if (!bIsActive) return false;
	return (CurrentTime - LastFireTime) >= FireRate;
}

bool UMShoot::ProcessMShoot(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMShoot] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
