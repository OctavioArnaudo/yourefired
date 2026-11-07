#include "MPatrol.h"

UMPatrol::UMPatrol()
	: IdentifierName(TEXT("MPatrol"))
	, bIsActive(true)
	, PatrolRadius(500.0f)
	, PatrolHomeLocation(FVector::ZeroVector)
{
}

bool UMPatrol::ProcessMPatrol(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UMPatrol] Processing Models operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
