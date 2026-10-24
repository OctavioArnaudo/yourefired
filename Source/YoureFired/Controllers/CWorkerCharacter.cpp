#include "WorkerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
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

	// 2.5D Sprite Visual Component (Plane mesh acting as a 2D Sprite model)
	SpriteVisualComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpriteVisualComponent"));
	SpriteVisualComponent->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlaneMeshAsset(TEXT("/Engine/BasicShapes/Plane.Plane"));
	if (PlaneMeshAsset.Succeeded())
	{
		SpriteVisualComponent->SetStaticMesh(PlaneMeshAsset.Object);
		// Rotate plane 90 degrees to stand vertically as a 2D sprite facing camera
		SpriteVisualComponent->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
		SpriteVisualComponent->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
	}

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
	UE_LOG(LogTemp, Log, TEXT("Worker performed Primary Ranged Attack (Left Click)"));
}

void AWorkerCharacter::SecondaryAttack()
{
	UE_LOG(LogTemp, Log, TEXT("Worker performed Secondary Melee Attack (Right Click)"));
}

void AWorkerCharacter::Interact()
{
	UE_LOG(LogTemp, Log, TEXT("Worker interacted / picked up item (Key Q)"));
}

void AWorkerCharacter::UseConsumable()
{
	if (CoffeeCount > 0)
	{
		CoffeeCount--;
		ReduceStress(25.0f);
		OnCoffeeCountChanged.Broadcast(CoffeeCount);
		UE_LOG(LogTemp, Log, TEXT("Worker drank Coffee (Key E)! Stress reduced by 25. Remaining Coffee: %d"), CoffeeCount);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Coffee available to consume!"));
	}
}

void AWorkerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AWorkerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AWorkerCharacter::MoveRight);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AWorkerCharacter::OnKeyQPressed);
	PlayerInputComponent->BindAction("UseConsumable", IE_Pressed, this, &AWorkerCharacter::OnKeyEPressed);
	PlayerInputComponent->BindAction("Settings", IE_Pressed, this, &AWorkerCharacter::OnKeyEscPressed);
	PlayerInputComponent->BindAction("TestVictory", IE_Pressed, this, &AWorkerCharacter::OnKeyVPressed);
	PlayerInputComponent->BindAction("TestDefeat", IE_Pressed, this, &AWorkerCharacter::OnKeyLPressed);
	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &AWorkerCharacter::OnLeftClickPressed);
	PlayerInputComponent->BindAction("SecondaryAttack", IE_Pressed, this, &AWorkerCharacter::OnRightClickPressed);
}

void AWorkerCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(FVector::ForwardVector, Value);
	}
}

void AWorkerCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(FVector::RightVector, Value);
	}
}

void AWorkerCharacter::OnKeyQPressed()
{
	Interact();
}

void AWorkerCharacter::OnKeyEPressed()
{
	UseConsumable();
}

void AWorkerCharacter::OnKeyEscPressed()
{
	UE_LOG(LogTemp, Log, TEXT("Jumping to Settings level via Esc..."));
	UGameplayStatics::OpenLevel(this, FName("/Game/YoureFired/Levels/Lvl_Settings"));
}

void AWorkerCharacter::OnKeyVPressed()
{
	UE_LOG(LogTemp, Log, TEXT("TEST: Triggering Victory condition via V!"));
	AOfficeGameMode* GM = Cast<AOfficeGameMode>(UGameplayStatics::GetGameMode(this));
	if (GM)
	{
		GM->OnFloorCompleted();
	}
}

void AWorkerCharacter::OnKeyLPressed()
{
	UE_LOG(LogTemp, Log, TEXT("TEST: Triggering Defeat condition via L!"));
	AddStress(MaxStress);
}

void AWorkerCharacter::OnLeftClickPressed()
{
	PrimaryAttack();
}

void AWorkerCharacter::OnRightClickPressed()
{
	SecondaryAttack();
}
