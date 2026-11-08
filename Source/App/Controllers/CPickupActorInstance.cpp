#include "CPickupActorInstance.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "App/Controllers/CPlayerCharacterInstance.h"

ACPickupActorInstance::ACPickupActorInstance()
	: HealAmount(25.0f)
{
	PrimaryActorTick.bCanEverTick = false;

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	RootComponent = PickupMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cone.Cone"));
	if (MeshAsset.Succeeded())
	{
		PickupMesh->SetStaticMesh(MeshAsset.Object);
		PickupMesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.8f));
	}

	PickupMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	PickupMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	PickupMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	PickupMesh->SetGenerateOverlapEvents(true);
}

void ACPickupActorInstance::BeginPlay()
{
	Super::BeginPlay();
	if (PickupMesh)
	{
		PickupMesh->OnComponentBeginOverlap.AddDynamic(this, &ACPickupActorInstance::OnPickupOverlap);
	}
}

void ACPickupActorInstance::OnPickupOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IsValid(OtherActor) && OtherActor != this)
	{
		ACPlayerCharacterInstance* Player = Cast<ACPlayerCharacterInstance>(OtherActor);
		if (IsValid(Player))
		{
			UE_LOG(LogTemp, Warning, TEXT("[ACPickupActorInstance] Player collected health pickup rhombus! Healing by %.2f"), HealAmount);
			Player->Heal(HealAmount);
			Destroy();
		}
	}
}
