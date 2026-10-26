#include "SSupervisorEnemy.h"

USSupervisorEnemy::USSupervisorEnemy()
	: IdentifierName(TEXT("SSupervisorEnemy")), bIsActive(true)
{
}

bool USSupervisorEnemy::ProcessSSupervisorEnemy(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USSupervisorEnemy] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
