#pragma once
#include "CoreMinimal.h"

class ACharacter;
class MSprint;
class MMovement;

class APP_API SSprint
{
public:
	SSprint();
	void SetSprintState(ACharacter* Character, MSprint& SprintModel, const MMovement& MovementModel, bool bStart);
};
