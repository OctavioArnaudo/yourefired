#include "OfficeGameState.h"

AOfficeGameState::AOfficeGameState()
{
	CurrentFloor = 1;
	SignaturesCollected = 0;
	RequiredSignatures = 3;
}

void AOfficeGameState::AddSignature()
{
	SignaturesCollected++;
	OnSignaturesUpdated.Broadcast(SignaturesCollected, RequiredSignatures);
}

bool AOfficeGameState::HasAllSignatures() const
{
	return SignaturesCollected >= RequiredSignatures;
}

void AOfficeGameState::SetCurrentFloor(int32 NewFloor)
{
	CurrentFloor = NewFloor;
	SignaturesCollected = 0;
	OnFloorChanged.Broadcast(CurrentFloor);
	OnSignaturesUpdated.Broadcast(SignaturesCollected, RequiredSignatures);
}
