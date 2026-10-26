#include "CCoworkerEnemy.h"

UCCoworkerEnemy::UCCoworkerEnemy()
	: IdentifierName(TEXT("CCoworkerEnemy")), bIsActive(true)
{
}

bool UCCoworkerEnemy::ProcessCCoworkerEnemy(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCCoworkerEnemy] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
