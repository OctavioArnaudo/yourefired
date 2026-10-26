#include "VSupervisorEnemy.h"

UVSupervisorEnemy::UVSupervisorEnemy()
	: IdentifierName(TEXT("VSupervisorEnemy")), bIsActive(true)
{
}

bool UVSupervisorEnemy::ProcessVSupervisorEnemy(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVSupervisorEnemy] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
