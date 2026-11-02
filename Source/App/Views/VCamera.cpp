#include "VCamera.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

VCamera::VCamera() {}

void VCamera::BuildCameraComponents(ACharacter* Owner, USpringArmComponent*& OutBoom, UCameraComponent*& OutCamera)
{
	if (!Owner) return;

	OutBoom = Owner->CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	OutBoom->SetupAttachment(Owner->GetRootComponent());
	OutBoom->SetUsingAbsoluteRotation(true);
	OutBoom->TargetArmLength = 1200.0f;
	OutBoom->SetRelativeRotation(FRotator(-55.0f, 0.0f, 0.0f));
	OutBoom->bDoCollisionTest = false;

	OutCamera = Owner->CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCameraComponent"));
	OutCamera->SetupAttachment(OutBoom, USpringArmComponent::SocketName);
	OutCamera->bUsePawnControlRotation = false;
}
