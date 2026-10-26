#include "MPlayerFb.h"

UMPlayerFb::UMPlayerFb()
	: IdentifierName(TEXT("MPlayerFb")), bIsActive(true)
{
}

bool UMPlayerFb::ProcessMPlayerFb(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMPlayerFb] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
