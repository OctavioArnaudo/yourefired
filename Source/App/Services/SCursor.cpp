#include "SCursor.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/KismetMathLibrary.h"

SCursor::SCursor() {}

void SCursor::OrientTowardsCursor(ACharacter* Character)
{
	if (!Character) return;
	APlayerController* PC = Cast<APlayerController>(Character->GetController());
	if (!PC) return;

	FHitResult HitResult;
	PC->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);

	if (HitResult.bBlockingHit)
	{
		FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(Character->GetActorLocation(), HitResult.ImpactPoint);
		FRotator NewRotation(0.0f, TargetRotation.Yaw, 0.0f);
		Character->SetActorRotation(NewRotation);
	}
}
