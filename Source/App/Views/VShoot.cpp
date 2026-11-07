#include "VShoot.h"

UVShoot::UVShoot()
	: IdentifierName(TEXT("VShoot")), bIsActive(true)
{
}

bool UVShoot::ProcessVShoot(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVShoot] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
