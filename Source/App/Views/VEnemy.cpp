#include "VEnemy.h"

UVEnemy::UVEnemy()
	: IdentifierName(TEXT("VEnemy")), bIsActive(true)
{
}

bool UVEnemy::ProcessVEnemy(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVEnemy] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
