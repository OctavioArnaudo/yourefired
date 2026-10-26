#include "ICoworkerEnemy.h"

UICoworkerEnemy::UICoworkerEnemy()
	: IdentifierName(TEXT("ICoworkerEnemy")), bIsActive(true)
{
}

bool UICoworkerEnemy::ProcessICoworkerEnemy(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UICoworkerEnemy] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
