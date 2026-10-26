#include "IMPlaceholder.h"

UIMPlaceholder::UIMPlaceholder()
	: IdentifierName(TEXT("IMPlaceholder")), bIsActive(true)
{
}

bool UIMPlaceholder::ProcessIMPlaceholder(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIMPlaceholder] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
