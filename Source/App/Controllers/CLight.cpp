#include "CLight.h"

UCLight::UCLight()
	: IdentifierName(TEXT("CLight")), bIsActive(true)
{
}

bool UCLight::ProcessCLight(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UCLight] Processing Controllers operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
