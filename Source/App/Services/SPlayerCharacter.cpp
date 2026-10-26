#include "SPlayerCharacter.h"

USPlayerCharacter::USPlayerCharacter()
	: IdentifierName(TEXT("SPlayerCharacter")), bIsActive(true)
{
}

bool USPlayerCharacter::ProcessSPlayerCharacter(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USPlayerCharacter] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
