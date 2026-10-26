#include "MPlayerMovement.h"

UMPlayerMovement::UMPlayerMovement()
	: IdentifierName(TEXT("MPlayerMovement")), bIsActive(true)
{
}

bool UMPlayerMovement::ProcessMPlayerMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMPlayerMovement] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
