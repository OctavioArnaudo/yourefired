#pragma once
#include "CoreMinimal.h"

class ACharacter;

class APP_API SCursor
{
public:
	SCursor();
	void OrientTowardsCursor(ACharacter* Character);
};
