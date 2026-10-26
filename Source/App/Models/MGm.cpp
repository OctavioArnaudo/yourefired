#include "MGm.h"

UMGm::UMGm()
	: IdentifierName(TEXT("MGm")), bIsActive(true)
{
}

bool UMGm::ProcessMGm(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMGm] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
