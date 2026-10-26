#include "CEnemy.h"

UCEnemy::UCEnemy()
	: IdentifierName(TEXT("CEnemy")), bIsActive(true)
{
}

bool UCEnemy::ProcessCEnemy(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCEnemy] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
