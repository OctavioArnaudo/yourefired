#include "VPlayerCharacterInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

VPlayerCharacterInstance::VPlayerCharacterInstance()
{
}

void VPlayerCharacterInstance::SetupVisuals(ACharacter* CharacterOwner, UStaticMeshComponent*& OutMesh, USpringArmComponent*& OutBoom, UCameraComponent*& OutCamera)
{
	if (!CharacterOwner) return;

	OutMesh = CharacterOwner->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VerticalRectangleMesh"));
	OutMesh->SetupAttachment(CharacterOwner->GetRootComponent());

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeMeshAsset.Succeeded())
	{
		OutMesh->SetStaticMesh(CubeMeshAsset.Object);
		OutMesh->SetRelativeScale3D(FVector(0.8f, 0.8f, 2.0f));
	}

	OutBoom = CharacterOwner->CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	OutBoom->SetupAttachment(CharacterOwner->GetRootComponent());
	OutBoom->SetUsingAbsoluteRotation(true);
	OutBoom->TargetArmLength = 1200.0f;
	OutBoom->SetRelativeRotation(FRotator(-55.0f, 0.0f, 0.0f));
	OutBoom->bDoCollisionTest = false;

	OutCamera = CharacterOwner->CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCameraComponent"));
	OutCamera->SetupAttachment(OutBoom, USpringArmComponent::SocketName);
	OutCamera->bUsePawnControlRotation = false;
}
