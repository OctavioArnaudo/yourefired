#include "MShoot.h"

UMShoot::UMShoot()
	: IdentifierName(TEXT("MShoot"))
	, bIsActive(true)
	, ProjectileSpeed(1000.0f)
	, ProjectileClass(nullptr)
{
}

bool UMShoot::ProcessMShoot(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMShoot] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
