#include "IWalk.h"

namespace App
{
	IWalk::IWalk()
	{
	}

	void IWalk::OnWalkStateChanged(bool bIsWalking)
	{
		UE_LOG(LogTemp, Log, TEXT("[IWalk] OnWalkStateChanged contract called with state: %s"), bIsWalking ? TEXT("True") : TEXT("False"));
	}
}
