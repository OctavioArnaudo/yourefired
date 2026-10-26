#include "SEnemy.h"

USEnemy::USEnemy()
	: IdentifierName(TEXT("SEnemy")), bIsActive(true)
{
}

bool USEnemy::ProcessSEnemy(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USEnemy] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
