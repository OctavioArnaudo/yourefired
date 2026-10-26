#include "VLight.h"

UVLight::UVLight()
	: IdentifierName(TEXT("VLight")), bIsActive(true)
{
}

bool UVLight::ProcessVLight(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVLight] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
