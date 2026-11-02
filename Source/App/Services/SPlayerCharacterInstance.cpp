#include "SPlayerCharacterInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "App/Models/MPlayerCharacterInstance.h"

SPlayerCharacterInstance::SPlayerCharacterInstance()
{
}

void SPlayerCharacterInstance::HandleMovement(ACharacter* Character, float Value, bool bForward)
{
	if (Character && Character->GetController() && Value != 0.0f)
	{
		FVector Direction = bForward ? FVector(1.0f, 0.0f, 0.0f) : FVector(0.0f, 1.0f, 0.0f);
		Character->AddMovementInput(Direction, Value);
	}
}

void SPlayerCharacterInstance::HandleSprint(ACharacter* Character, MPlayerCharacterInstance& Model, bool bStart)
{
	Model.bIsSprinting = bStart;
	if (Character && Character->GetCharacterMovement())
	{
		Character->GetCharacterMovement()->MaxWalkSpeed = bStart ? Model.SprintSpeed : Model.WalkSpeed;
	}
}

void SPlayerCharacterInstance::RotateTowardsCursor(ACharacter* Character)
{
	if (!Character) return;
	APlayerController* PC = Cast<APlayerController>(Character->GetController());
	if (!PC) return;

	FHitResult HitResult;
	PC->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);

	if (HitResult.bBlockingHit)
	{
		FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(Character->GetActorLocation(), HitResult.ImpactPoint);
		FRotator NewRotation(0.0f, TargetRotation.Yaw, 0.0f);
		Character->SetActorRotation(NewRotation);
	}
}

void SPlayerCharacterInstance::PerformMeleeAttack()
{
	UE_LOG(LogTemp, Log, TEXT("[Service] Melee attack executed towards cursor!"));
}

void SPlayerCharacterInstance::PerformRangedAttack(ACharacter* Character, const MPlayerCharacterInstance& Model)
{
	if (!Character) return;
	if (!Model.ProjectileClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("[Service] No ProjectileClass assigned!"));
		return;
	}

	FVector SpawnLocation = Character->GetActorLocation() + (Character->GetActorForwardVector() * Model.RangedSpawnOffset);
	FRotator SpawnRotation = Character->GetActorRotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	SpawnParams.Owner = Character;
	SpawnParams.Instigator = Cast<APawn>(Character);

	AActor* SpawnedProjectile = Character->GetWorld()->SpawnActor<AActor>(Model.ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
	if (SpawnedProjectile)
	{
		UE_LOG(LogTemp, Log, TEXT("[Service] Ranged projectile spawned successfully!"));
	}
}
