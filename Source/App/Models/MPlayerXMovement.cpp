#include "MPlayerXMovement.h"

UMPlayerXMovement::UMPlayerXMovement()
	: IdentifierName(TEXT("MPlayerXMovement")), bIsActive(true)
{
}

bool UMPlayerXMovement::ProcessMPlayerXMovement(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMPlayerXMovement] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
