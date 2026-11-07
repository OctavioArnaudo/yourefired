#include "CShoot.h"

UCShoot::UCShoot()
	: IdentifierName(TEXT("CShoot")), bIsActive(true)
{
}

void UCShoot::StartFiring(UMShoot* ShootModel)
{
	if (ShootModel)
	{
		ShootModel->bIsFiring = true;
		UE_LOG(LogTemp, Log, TEXT("[UCShoot] Firing started."));
	}
}

void UCShoot::StopFiring(UMShoot* ShootModel)
{
	if (ShootModel)
	{
		ShootModel->bIsFiring = false;
		UE_LOG(LogTemp, Log, TEXT("[UCShoot] Firing stopped."));
	}
}

bool UCShoot::ProcessCShoot(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCShoot] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
