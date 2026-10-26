#include "IEnemy.h"

UIEnemy::UIEnemy()
	: IdentifierName(TEXT("IEnemy")), bIsActive(true)
{
}

bool UIEnemy::ProcessIEnemy(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIEnemy] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
