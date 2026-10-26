#include "COfficePerimeter.h"

UCOfficePerimeter::UCOfficePerimeter()
	: IdentifierName(TEXT("COfficePerimeter")), bIsActive(true)
{
}

bool UCOfficePerimeter::ProcessCOfficePerimeter(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCOfficePerimeter] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
