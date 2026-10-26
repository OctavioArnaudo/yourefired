#include "MEnvironment.h"

UMEnvironment::UMEnvironment()
	: IdentifierName(TEXT("MEnvironment")), bIsActive(true)
{
}

bool UMEnvironment::ProcessMEnvironment(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMEnvironment] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
