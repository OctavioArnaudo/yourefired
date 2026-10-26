#include "IOfficePerimeter.h"

UIOfficePerimeter::UIOfficePerimeter()
	: IdentifierName(TEXT("IOfficePerimeter")), bIsActive(true)
{
}

bool UIOfficePerimeter::ProcessIOfficePerimeter(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIOfficePerimeter] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
