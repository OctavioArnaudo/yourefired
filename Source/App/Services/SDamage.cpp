#include "SDamage.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "App/Controllers/CPlayerCharacterInstance.h"
#include "App/Controllers/CEnemyCharacterInstance.h"

USDamage::USDamage()
	: IdentifierName(TEXT("SDamage")), bIsActive(true)
{
}

bool USDamage::ProcessSDamage(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USDamage] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}

void USDamage::ApplyDamageUniversal(AActor* Target, float DamageAmount, AController* EventInstigator, AActor* DamageCauser)
{
	if (!IsValid(Target)) return;

	UE_LOG(LogTemp, Warning, TEXT("[USDamage] Universal Damage Application: Applying %.2f damage to target '%s' (Class: %s)"),
		DamageAmount, *Target->GetName(), *Target->GetClass()->GetName());

	ACPlayerCharacterInstance* PlayerTarget = Cast<ACPlayerCharacterInstance>(Target);
	if (IsValid(PlayerTarget))
	{
		PlayerTarget->ReceiveDamageDirect(DamageAmount);
		return;
	}

	ACEnemyCharacterInstance* EnemyTarget = Cast<ACEnemyCharacterInstance>(Target);
	if (IsValid(EnemyTarget))
	{
		EnemyTarget->ReceiveDamageDirect(DamageAmount);
		return;
	}

	UGameplayStatics::ApplyDamage(Target, DamageAmount, EventInstigator, DamageCauser, UDamageType::StaticClass());
}
