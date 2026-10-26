#include "ISupervisorEnemy.h"

UISupervisorEnemy::UISupervisorEnemy()
	: IdentifierName(TEXT("ISupervisorEnemy")), bIsActive(true)
{
}

bool UISupervisorEnemy::ProcessISupervisorEnemy(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UISupervisorEnemy] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
