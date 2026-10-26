#include "IPlayerCharacter.h"

UIPlayerCharacter::UIPlayerCharacter()
	: IdentifierName(TEXT("IPlayerCharacter")), bIsActive(true)
{
}

bool UIPlayerCharacter::ProcessIPlayerCharacter(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIPlayerCharacter] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
