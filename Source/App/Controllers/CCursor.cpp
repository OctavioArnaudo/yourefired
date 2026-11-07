#include "CCursor.h"
#include "GameFramework/PlayerController.h"

CCursor::CCursor()
{
}

bool CCursor::TraceCursorToWorld(APlayerController* PC, MCursor& OutCursorModel)
{
	if (!PC) return false;

	FHitResult Hit;
	if (PC->GetHitResultUnderCursor(ECC_Visibility, false, Hit))
	{
		OutCursorModel.WorldLocation = Hit.Location;
		OutCursorModel.bIsValid = true;
		UE_LOG(LogTemp, Log, TEXT("[CCursor] Cursor hit at: %s"), *Hit.Location.ToString());
		return true;
	}
	return false;
}
