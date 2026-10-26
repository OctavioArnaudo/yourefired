#include "CPlayerCharacter.h"

UCPlayerCharacter::UCPlayerCharacter()
	: IdentifierName(TEXT("CPlayerCharacter")), bIsActive(true)
{
}

bool UCPlayerCharacter::ProcessCPlayerCharacter(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCPlayerCharacter] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
