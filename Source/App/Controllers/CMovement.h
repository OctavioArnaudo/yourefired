#pragma once

#include "CoreMinimal.h"

class ACharacter;

class APP_API CMovement
{
public:
	CMovement();

	void HandleMovementInput(ACharacter* Character, float AxisValue, bool bForward);
};
