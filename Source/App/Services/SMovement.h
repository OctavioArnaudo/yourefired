#pragma once
#include "CoreMinimal.h"

class ACharacter;

class APP_API SMovement
{
public:
	SMovement();
	void ApplyMovement(ACharacter* Character, float Value, bool bForward);
};
