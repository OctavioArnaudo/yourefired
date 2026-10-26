#include "VCoworkerEnemy.h"

UVCoworkerEnemy::UVCoworkerEnemy()
	: IdentifierName(TEXT("VCoworkerEnemy")), bIsActive(true)
{
}

bool UVCoworkerEnemy::ProcessVCoworkerEnemy(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVCoworkerEnemy] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
