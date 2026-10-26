#include "MSupervisorEnemy.h"

UMSupervisorEnemy::UMSupervisorEnemy()
	: IdentifierName(TEXT("MSupervisorEnemy")), bIsActive(true)
{
}

bool UMSupervisorEnemy::ProcessMSupervisorEnemy(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMSupervisorEnemy] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
