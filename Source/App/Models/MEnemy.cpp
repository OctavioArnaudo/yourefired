#include "MEnemy.h"

UMEnemy::UMEnemy()
	: IdentifierName(TEXT("MEnemy")), bIsActive(true)
{
}

bool UMEnemy::ProcessMEnemy(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMEnemy] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
