#pragma once

#include "CoreMinimal.h"

class APP_API VCursor
{
public:
	VCursor();

	void DrawCrosshairFX(const FVector2D& ScreenPos);
};
