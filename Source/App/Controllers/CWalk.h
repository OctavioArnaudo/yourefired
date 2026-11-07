#pragma once

#include "CoreMinimal.h"
#include "App/Models/MWalk.h"

class ACharacter;

class APP_API CWalk
{
public:
	CWalk();

	void UpdateWalkSpeed(ACharacter* Character, MWalk& WalkModel, float NewSpeed);
};
