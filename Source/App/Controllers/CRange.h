#pragma once

#include "CoreMinimal.h"
#include "App/Models/MRange.h"

class AActor;

class APP_API CRange
{
public:
	CRange();

	bool IsInRange(AActor* Origin, AActor* Target, const MRange& RangeModel);
};
