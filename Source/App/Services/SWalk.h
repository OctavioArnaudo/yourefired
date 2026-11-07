#pragma once

#include "CoreMinimal.h"

class ACharacter;
class MWalk;

class APP_API SWalk
{
public:
	SWalk();

	void ApplyWalkMode(ACharacter* Character, const MWalk& WalkModel);
};
