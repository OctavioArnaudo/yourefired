#include "CColor.h"

UCColor::UCColor()
	: IdentifierName(TEXT("CColor")), bIsActive(true)
{
}

bool UCColor::ProcessCColor(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCColor] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
