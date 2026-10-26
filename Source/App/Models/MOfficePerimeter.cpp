#include "MOfficePerimeter.h"

UMOfficePerimeter::UMOfficePerimeter()
	: IdentifierName(TEXT("MOfficePerimeter")), bIsActive(true)
{
}

bool UMOfficePerimeter::ProcessMOfficePerimeter(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMOfficePerimeter] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
