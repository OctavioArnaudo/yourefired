#include "CSupervisorEnemy.h"

UCSupervisorEnemy::UCSupervisorEnemy()
	: IdentifierName(TEXT("CSupervisorEnemy")), bIsActive(true)
{
}

bool UCSupervisorEnemy::ProcessCSupervisorEnemy(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCSupervisorEnemy] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
