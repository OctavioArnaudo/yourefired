#include "WorkerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "OfficeGameMode.h"
#include "Kismet/GameplayStatics.h"

AWorkerCharacter::AWorkerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Stress Defaults
	CurrentStress = 0.0f;
	MaxStress = 100.0f;
	CoffeeCount = 0;

	// Top-Down Camera Setup
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->TargetArmLength = 1200.0f;
	CameraBoom->SetRelativeRotation(FRotator(-60.0f, 0.0f, 0.0f));
	CameraBoom->bDoCollisionTest = false;

	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false;

	// Character Movement Setup for Top-Down
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 640.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0.0f, 0.0f, 1.0f));

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AWorkerCharacter::BeginPlay()
{
	Super::BeginPlay();
	OnStressChanged.Broadcast(CurrentStress, MaxStress);
	OnCoffeeCountChanged.Broadcast(CoffeeCount);
}

void AWorkerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AWorkerCharacter::AddStress(float Amount)
{
	CurrentStress = FMath::Clamp(CurrentStress + Amount, 0.0f, MaxStress);
	OnStressChanged.Broadcast(CurrentStress, MaxStress);

	if (CurrentStress >= MaxStress)
	{
		AOfficeGameMode* GM = Cast<AOfficeGameMode>(UGameplayStatics::GetGameMode(this));
		if (GM)
		{
			GM->OnPlayerFired();
		}
	}
}

void AWorkerCharacter::ReduceStress(float Amount)
{
	CurrentStress = FMath::Clamp(CurrentStress - Amount, 0.0f, MaxStress);
	OnStressChanged.Broadcast(CurrentStress, MaxStress);
}

void AWorkerCharacter::AddCoffee(int32 Amount)
{
	CoffeeCount += Amount;
	OnCoffeeCountChanged.Broadcast(CoffeeCount);
}

void AWorkerCharacter::PrimaryAttack()
{
	UE_LOG(LogTemp, Log, TEXT("Worker performed Primary Attack (Melee/Paper Airplane)"));
}

void AWorkerCharacter::SecondaryAttack()
{
	UE_LOG(LogTemp, Log, TEXT("Worker performed Secondary Attack (Throwing Current Item)"));
}

void AWorkerCharacter::Interact()
{
	UE_LOG(LogTemp, Log, TEXT("Worker interacted with office environment"));
}

void AWorkerCharacter::UseConsumable()
{
	if (CoffeeCount > 0)
	{
		CoffeeCount--;
		ReduceStress(25.0f);
		OnCoffeeCountChanged.Broadcast(CoffeeCount);
		UE_LOG(LogTemp, Log, TEXT("Worker drank Coffee! Stress reduced by 25. Remaining Coffee: %d"), CoffeeCount);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Coffee available to consume!"));
	}
}
