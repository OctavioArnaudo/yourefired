#include "ISprint.h"

namespace App
{
	ISprint::ISprint()
	{
	}

	void ISprint::OnSprintToggled(bool bIsSprinting)
	{
		UE_LOG(LogTemp, Log, TEXT("[ISprint] OnSprintToggled contract called with: %s"), bIsSprinting ? TEXT("True") : TEXT("False"));
	}
}
