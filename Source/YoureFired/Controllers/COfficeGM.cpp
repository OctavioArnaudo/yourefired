#include "YoureFiredGM.h"
#include "OfficeGameState.h"
#include "OfficePlayerController.h"
#include "WorkerCharacter.h"
#include "Kismet/GameplayStatics.h"

AYoureFiredGM::AYoureFiredGM()
{
	DefaultPawnClass = AWorkerCharacter::StaticClass();
	PlayerControllerClass = AOfficePlayerController::StaticClass();
	GameStateClass = AOfficeGameState::StaticClass();
}

void AYoureFiredGM::BeginPlay()
{
	Super::BeginPlay();
}

void AYoureFiredGM::OnPlayerFired()
{
	UE_LOG(LogTemp, Warning, TEXT("Game Over: Stress level reached maximum. You're Fired!"));
	OnGameOver.Broadcast();
}

void AYoureFiredGM::OnFloorCompleted()
{
	AOfficeGameState* GS = GetGameState<AOfficeGameState>();
	if (GS)
	{
		UE_LOG(LogTemp, Log, TEXT("Floor %d Completed!"), GS->CurrentFloor);
		OnFloorComplete.Broadcast(GS->CurrentFloor);

		int32 NextFloor = GS->CurrentFloor + 1;
		if (NextFloor <= 4)
		{
			GS->SetCurrentFloor(NextFloor);
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Game Victory! Reached and confronted the Executive Board!"));
		}
	}
}
