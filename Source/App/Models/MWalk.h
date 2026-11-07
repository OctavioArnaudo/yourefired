#pragma once

#include "CoreMinimal.h"

class APP_API MWalk
{
public:
	MWalk();

	float WalkSpeed;
	float WalkAcceleration;
	bool bIsWalking;

	void SetWalkSpeed(float NewSpeed);
};
