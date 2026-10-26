#include "MPlayerXyzMovement.h"

UMPlayerXyzMovement::UMPlayerXyzMovement()
	: IdentifierName(TEXT("MPlayerXyzMovement")), bIsActive(true)
{
}

bool UMPlayerXyzMovement::ProcessMPlayerXyzMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMPlayerXyzMovement] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
