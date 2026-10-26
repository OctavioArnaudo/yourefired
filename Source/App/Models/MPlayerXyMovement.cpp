#include "MPlayerXyMovement.h"

UMPlayerXyMovement::UMPlayerXyMovement()
	: IdentifierName(TEXT("MPlayerXyMovement")), bIsActive(true)
{
}

bool UMPlayerXyMovement::ProcessMPlayerXyMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMPlayerXyMovement] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
