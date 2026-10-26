#include "VPlayerCharacter.h"

UVPlayerCharacter::UVPlayerCharacter()
	: IdentifierName(TEXT("VPlayerCharacter")), bIsActive(true)
{
}

bool UVPlayerCharacter::ProcessVPlayerCharacter(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVPlayerCharacter] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
