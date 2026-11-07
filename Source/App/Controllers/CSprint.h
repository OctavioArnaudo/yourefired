#pragma once

#include "CoreMinimal.h"
#include "App/Models/MSprint.h"

class ACharacter;

class APP_API CSprint
{
public:
	CSprint();

	void ToggleSprint(ACharacter* Character, MSprint& SprintModel, bool bStart);
};
