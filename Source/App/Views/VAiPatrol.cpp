#include "VAiPatrol.h"

UVAiPatrol::UVAiPatrol()
	: IdentifierName(TEXT("VAiPatrol")), bIsActive(true)
{
}

bool UVAiPatrol::ProcessVAiPatrol(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[UVAiPatrol] Processing Views operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}
