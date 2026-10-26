#include "IColor.h"

UIColor::UIColor()
	: IdentifierName(TEXT("IColor")), bIsActive(true)
{
}

bool UIColor::ProcessIColor(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIColor] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
