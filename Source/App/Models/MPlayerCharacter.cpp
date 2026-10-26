#include "MPlayerCharacter.h"

UMPlayerCharacter::UMPlayerCharacter()
	: IdentifierName(TEXT("MPlayerCharacter")), bIsActive(true)
{
}

bool UMPlayerCharacter::ProcessMPlayerCharacter(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMPlayerCharacter] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
