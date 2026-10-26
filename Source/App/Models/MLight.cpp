#include "MLight.h"

UMLight::UMLight()
	: IdentifierName(TEXT("MLight")), bIsActive(true)
{
}

bool UMLight::ProcessMLight(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMLight] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
