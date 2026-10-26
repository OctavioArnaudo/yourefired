#include "MPlayerActor.h"

UMPlayerActor::UMPlayerActor()
	: IdentifierName(TEXT("MPlayerActor")), bIsActive(true)
{
}

bool UMPlayerActor::ProcessMPlayerActor(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMPlayerActor] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
