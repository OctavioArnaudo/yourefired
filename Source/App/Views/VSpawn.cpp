#include "VSpawn.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

VSpawn::VSpawn() {}

void VSpawn::BuildPlayerMesh(ACharacter* Owner, UStaticMeshComponent*& OutMesh)
{
	if (!Owner) return;

	OutMesh = Owner->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VerticalRectangleMesh"));
	OutMesh->SetupAttachment(Owner->GetRootComponent());

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeMeshAsset.Succeeded())
	{
		OutMesh->SetStaticMesh(CubeMeshAsset.Object);
		OutMesh->SetRelativeScale3D(FVector(0.8f, 0.8f, 2.0f));
	}
}
