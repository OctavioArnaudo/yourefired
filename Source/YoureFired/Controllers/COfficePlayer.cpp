#include "OfficePlayerController.h"
#include "WorkerCharacter.h"

AOfficePlayerController::AOfficePlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
}

void AOfficePlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameAndUI InputMode;
	InputMode.SetHideCursorDuringCapture(false);
	SetInputMode(InputMode);
}

void AOfficePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &AOfficePlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AOfficePlayerController::MoveRight);

	InputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &AOfficePlayerController::PrimaryAttack);
	InputComponent->BindAction("SecondaryAttack", IE_Pressed, this, &AOfficePlayerController::SecondaryAttack);
	InputComponent->BindAction("Interact", IE_Pressed, this, &AOfficePlayerController::Interact);
	InputComponent->BindAction("UseConsumable", IE_Pressed, this, &AOfficePlayerController::UseConsumable);
}

void AOfficePlayerController::MoveForward(float Value)
{
	if (Value != 0.0f && GetPawn())
	{
		GetPawn()->AddMovementInput(FVector::ForwardVector, Value);
	}
}

void AOfficePlayerController::MoveRight(float Value)
{
	if (Value != 0.0f && GetPawn())
	{
		GetPawn()->AddMovementInput(FVector::RightVector, Value);
	}
}

void AOfficePlayerController::PrimaryAttack()
{
	AWorkerCharacter* Worker = Cast<AWorkerCharacter>(GetPawn());
	if (Worker)
	{
		Worker->PrimaryAttack();
	}
}

void AOfficePlayerController::SecondaryAttack()
{
	AWorkerCharacter* Worker = Cast<AWorkerCharacter>(GetPawn());
	if (Worker)
	{
		Worker->SecondaryAttack();
	}
}

void AOfficePlayerController::Interact()
{
	AWorkerCharacter* Worker = Cast<AWorkerCharacter>(GetPawn());
	if (Worker)
	{
		Worker->Interact();
	}
}

void AOfficePlayerController::UseConsumable()
{
	AWorkerCharacter* Worker = Cast<AWorkerCharacter>(GetPawn());
	if (Worker)
	{
		Worker->UseConsumable();
	}
}
