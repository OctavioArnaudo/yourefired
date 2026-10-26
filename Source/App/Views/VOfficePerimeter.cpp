#include "VOfficePerimeter.h"

UVOfficePerimeter::UVOfficePerimeter()
	: IdentifierName(TEXT("VOfficePerimeter")), bIsActive(true)
{
}

bool UVOfficePerimeter::ProcessVOfficePerimeter(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVOfficePerimeter] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
