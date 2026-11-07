#include "VEnemyCharacterInstance.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

VEnemyCharacterInstance::VEnemyCharacterInstance() {}

void VEnemyCharacterInstance::SetupVisuals(ACharacter* CharacterOwner, UStaticMeshComponent*& OutMesh)
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
}
