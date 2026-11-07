#include "MWalk.h"

MWalk::MWalk()
	: WalkSpeed(300.0f)
	, WalkAcceleration(2048.0f)
	, bIsWalking(false)
{
}

void MWalk::SetWalkSpeed(float NewSpeed)
{
	WalkSpeed = FMath::Max(0.0f, NewSpeed);
}
