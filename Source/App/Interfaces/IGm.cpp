#include "IGm.h"

UIGm::UIGm()
	: IdentifierName(TEXT("IGm")), bIsActive(true)
{
}

bool UIGm::ProcessIGm(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UIGm] Processing Interfaces operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
