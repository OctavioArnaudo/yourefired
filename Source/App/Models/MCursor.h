#pragma once

#include "CoreMinimal.h"

class APP_API MCursor
{
public:
	MCursor();

	FVector WorldLocation;
	FVector WorldDirection;
	bool bIsValid;
};
