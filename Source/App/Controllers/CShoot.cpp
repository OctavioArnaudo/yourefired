#include "CShoot.h"

UCShoot::UCShoot()
	: IdentifierName(TEXT("CShoot")), bIsActive(true)
{
}

bool UCShoot::ProcessCShoot(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCShoot] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
