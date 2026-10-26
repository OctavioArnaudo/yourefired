#include "SColor.h"

USColor::USColor()
	: IdentifierName(TEXT("SColor")), bIsActive(true)
{
}

bool USColor::ProcessSColor(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USColor] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
