#include "SignaturePickup.h"
#include "OfficeGameState.h"
#include "Kismet/GameplayStatics.h"

ASignaturePickup::ASignaturePickup()
{
}

void ASignaturePickup::OnPickedUp(AActor* PickupInstigator)
{
	AOfficeGameState* GS = Cast<AOfficeGameState>(UGameplayStatics::GetGameState(this));
	if (GS)
	{
		GS->AddSignature();
		UE_LOG(LogTemp, Log, TEXT("Approval Signature collected! Total signatures: %d/%d"), GS->SignaturesCollected, GS->RequiredSignatures);
	}
	Destroy();
}
