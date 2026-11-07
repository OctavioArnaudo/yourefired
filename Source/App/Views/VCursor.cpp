#include "VCursor.h"

VCursor::VCursor()
{
}

void VCursor::DrawCrosshairFX(const FVector2D& ScreenPos)
{
	UE_LOG(LogTemp, Log, TEXT("[VCursor] Drawing crosshair at (%.1f, %.1f)"), ScreenPos.X, ScreenPos.Y);
}
