#include "SCoworkerEnemy.h"

USCoworkerEnemy::USCoworkerEnemy()
	: IdentifierName(TEXT("SCoworkerEnemy")), bIsActive(true)
{
}

bool USCoworkerEnemy::ProcessSCoworkerEnemy(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USCoworkerEnemy] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
