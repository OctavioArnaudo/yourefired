#pragma once

#include "CoreMinimal.h"
#include "App/Models/MCursor.h"

class APlayerController;

class APP_API CCursor
{
public:
	CCursor();

	bool TraceCursorToWorld(APlayerController* PC, MCursor& OutCursorModel);
};
