#include "SOfficePerimeter.h"

USOfficePerimeter::USOfficePerimeter()
	: IdentifierName(TEXT("SOfficePerimeter")), bIsActive(true)
{
}

bool USOfficePerimeter::ProcessSOfficePerimeter(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USOfficePerimeter] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
