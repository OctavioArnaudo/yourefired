#include "OfficeDoor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "OfficeGameState.h"
#include "OfficeGameMode.h"
#include "WorkerCharacter.h"
#include "Kismet/GameplayStatics.h"

AOfficeDoor::AOfficeDoor()
{
	PrimaryActorTick.bCanEverTick = false;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	RootComponent = DoorMesh;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(RootComponent);
	TriggerBox->SetBoxExtent(FVector(100.0f, 100.0f, 100.0f));

	bIsUnlocked = false;
}

void AOfficeDoor::BeginPlay()
{
	Super::BeginPlay();
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AOfficeDoor::OnOverlap);
}

void AOfficeDoor::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<AWorkerCharacter>(OtherActor))
	{
		TryOpenDoor(OtherActor);
	}
}

bool AOfficeDoor::TryOpenDoor(AActor* InstigatorActor)
{
	AOfficeGameState* GS = Cast<AOfficeGameState>(UGameplayStatics::GetGameState(this));
	if (GS && GS->HasAllSignatures())
	{
		bIsUnlocked = true;
		UE_LOG(LogTemp, Log, TEXT("Door Unlocked! Transitioning floor."));

		AOfficeGameMode* GM = Cast<AOfficeGameMode>(UGameplayStatics::GetGameMode(this));
		if (GM)
		{
			GM->OnFloorCompleted();
		}
		return true;
	}
	else
	{
		int32 Missing = GS ? (GS->RequiredSignatures - GS->SignaturesCollected) : 0;
		UE_LOG(LogTemp, Warning, TEXT("Door Locked! You need %d more Approval Signatures."), Missing);
		return false;
	}
}
