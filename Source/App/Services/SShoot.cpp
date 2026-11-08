#include "SShoot.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "App/Controllers/CProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/DamageEvents.h"
#include "App/Controllers/CPlayerCharacterInstance.h"
#include "App/Controllers/CEnemyCharacterInstance.h"

USShoot::USShoot()
	: IdentifierName(TEXT("SShoot")), bIsActive(true)
{
}

bool USShoot::ProcessSShoot(const FVector& TargetLocation)
{
	UE_LOG(LogTemp, Log, TEXT("[USShoot] Processing Services operation for '%s' at %s."), *IdentifierName, *TargetLocation.ToString());
	return bIsActive;
}

static void ApplyDamageUniversal(AActor* Target, float DamageAmount, AController* EventInstigator, AActor* DamageCauser)
{
	if (!IsValid(Target)) return;

	UE_LOG(LogTemp, Warning, TEXT("[UniversalDamage] Shoot applying %.2f damage to target '%s' (Class: %s)"),
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

	UFunction* Func = Target->FindFunction(FName("ReceiveDamageDirect"));
	if (Func)
	{
		struct FParams { float Amount; };
		FParams Parms;
		Parms.Amount = DamageAmount;
		Target->ProcessEvent(Func, &Parms);
		return;
	}

	UGameplayStatics::ApplyDamage(Target, DamageAmount, EventInstigator, DamageCauser, UDamageType::StaticClass());
}

bool USShoot::PerformRangedShoot(ACharacter* Shooter, TSubclassOf<AActor> ProjectileClass)
{
	if (!IsValid(Shooter) || !IsValid(Shooter->GetWorld())) return false;

	UWorld* World = Shooter->GetWorld();

	// 1. Spawn visual projectile for feedback
	TSubclassOf<AActor> ClassToSpawn = ProjectileClass;
	if (!ClassToSpawn)
	{
		ClassToSpawn = ACProjectile::StaticClass();
	}

	FVector SpawnLocation = Shooter->GetActorLocation() + (Shooter->GetActorForwardVector() * 100.0f);
	FRotator SpawnRotation = Shooter->GetActorRotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Owner = Shooter;
	SpawnParams.Instigator = Shooter;

	AActor* SpawnedActor = World->SpawnActor<AActor>(ClassToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
	if (IsValid(SpawnedActor))
	{
		ACProjectile* Proj = Cast<ACProjectile>(SpawnedActor);
		if (IsValid(Proj))
		{
			Proj->ShooterActor = Shooter;
			Proj->SetActorRotation(SpawnRotation);
			if (Proj->ProjectileMovement)
			{
				Proj->ProjectileMovement->SetUpdatedComponent(Proj->GetRootComponent());
				Proj->ProjectileMovement->Velocity = SpawnRotation.Vector() * Proj->ProjectileMovement->InitialSpeed;
				Proj->ProjectileMovement->Activate();
			}
		}
	}

	// 2. Instant Sphere Sweep for 100% reliable hit detection and damage
	FVector StartLoc = Shooter->GetActorLocation() + (Shooter->GetActorForwardVector() * 50.0f);
	FVector EndLoc = StartLoc + (Shooter->GetActorForwardVector() * 2500.0f);

	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(Shooter);

	bool bHit = World->SweepSingleByChannel(
		HitResult,
		StartLoc,
		EndLoc,
		FQuat::Identity,
		ECC_Pawn,
		FCollisionShape::MakeSphere(80.0f),
		QueryParams
	);

	if (bHit && IsValid(HitResult.GetActor()))
	{
		AActor* HitActor = HitResult.GetActor();
		if (HitActor != Shooter)
		{
			UE_LOG(LogTemp, Warning, TEXT("[USShoot] Ranged sweep hit target '%s'! Applying damage."), *HitActor->GetName());
			ApplyDamageUniversal(HitActor, 25.0f, Shooter->GetController(), Shooter);
		}
	}

	return true;
}

bool USShoot::PerformDiscreteRangedShoot(ACharacter* Shooter, UMShoot* ShootModel, TSubclassOf<AActor> ProjectileClass, float CurrentTime)
{
	if (!IsValid(Shooter) || !IsValid(Shooter->GetWorld()) || !ShootModel) return false;

	if (!ShootModel->CanFire(CurrentTime))
	{
		return false;
	}

	ShootModel->LastFireTime = CurrentTime;

	UWorld* World = Shooter->GetWorld();

	// 1. Spawn visual projectile
	TSubclassOf<AActor> ClassToSpawn = ProjectileClass ? ProjectileClass : ShootModel->ProjectileClass;
	if (!ClassToSpawn)
	{
		ClassToSpawn = ACProjectile::StaticClass();
	}

	FVector SpawnLocation = Shooter->GetActorLocation() + (Shooter->GetActorForwardVector() * 100.0f);
	FRotator SpawnRotation = Shooter->GetActorRotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Owner = Shooter;
	SpawnParams.Instigator = Shooter;

	AActor* SpawnedActor = World->SpawnActor<AActor>(ClassToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
	if (IsValid(SpawnedActor))
	{
		ACProjectile* Proj = Cast<ACProjectile>(SpawnedActor);
		if (IsValid(Proj))
		{
			Proj->ShooterActor = Shooter;
			Proj->SetActorRotation(SpawnRotation);
			if (Proj->ProjectileMovement)
			{
				Proj->ProjectileMovement->SetUpdatedComponent(Proj->GetRootComponent());
				Proj->ProjectileMovement->Velocity = SpawnRotation.Vector() * Proj->ProjectileMovement->InitialSpeed;
				Proj->ProjectileMovement->Activate();
			}
		}
	}

	// 2. Instant Sphere Sweep for 100% reliable hit detection and damage
	FVector StartLoc = Shooter->GetActorLocation() + (Shooter->GetActorForwardVector() * 50.0f);
	FVector EndLoc = StartLoc + (Shooter->GetActorForwardVector() * 2500.0f);

	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(Shooter);

	bool bHit = World->SweepSingleByChannel(
		HitResult,
		StartLoc,
		EndLoc,
		FQuat::Identity,
	   ECC_Pawn,
		FCollisionShape::MakeSphere(80.0f),
		QueryParams
	);

	if (bHit && IsValid(HitResult.GetActor()))
	{
		AActor* HitActor = HitResult.GetActor();
		if (HitActor != Shooter)
		{
			UE_LOG(LogTemp, Warning, TEXT("[USShoot] Discrete ranged sweep hit target '%s'! Applying damage."), *HitActor->GetName());
			ApplyDamageUniversal(HitActor, 25.0f, Shooter->GetController(), Shooter);
		}
	}

	return true;
}
