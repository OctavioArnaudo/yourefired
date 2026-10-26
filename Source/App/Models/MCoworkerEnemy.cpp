#include "MCoworkerEnemy.h"

UMCoworkerEnemy::UMCoworkerEnemy()
	: IdentifierName(TEXT("MCoworkerEnemy")), bIsActive(true)
{
}

bool UMCoworkerEnemy::ProcessMCoworkerEnemy(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMCoworkerEnemy] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
