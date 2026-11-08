#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "App/Models/MPlayerCharacterInstance.h"
#include "App/Views/VPlayerCharacterInstance.h"
#include "App/Services/SPlayerCharacterInstance.h"
#include "CMovement.h"
#include "CHealth.h"
#include "CSprint.h"
#include "CWalk.h"
#include "CRange.h"
#include "CProjectile.h"
#include "CSpawn.h"
#include "CCamera.h"
#include "CCursor.h"
#include "CShoot.h"
#include "CPlayerCharacterInstance.generated.h"

class UCameraComponent;
class USSpringArmComponent;
class UStaticMeshComponent;

UCLASS()
class APP_API ACPlayerCharacterInstance : public ACharacter
{
	GENERATED_BODY()

public:
	ACPlayerCharacterInstance();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintCallable, Category = "Health")
	float ReceiveDamageDirect(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Health")
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Health")
	float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Health")
	float GetHealthPercent() const;

	UFUNCTION(BlueprintCallable, Category = "Health")
	bool IsDead() const;

	UFUNCTION(BlueprintCallable, Category = "Health")
	float Heal(float HealAmount);

	void FireBullet();

private:
	MPlayerCharacterInstance PlayerModel;
	VPlayerCharacterInstance PlayerView;
	SPlayerCharacterInstance PlayerService;

	CMovement MovementController;
	CHealth HealthController;
	CSprint SprintController;
	CWalk WalkController;
	CRange RangeController;
	CSpawn SpawnController;
	CCamera CameraController;
	CCursor CursorController;

	UPROPERTY()
	UCShoot* ShootController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* VerticalRectangleMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* TopDownCameraComponent;

	FTimerHandle FiringTimerHandle;
	bool bIsRangedAttacking;

	void MoveForward(float Value);
	void MoveRight(float Value);

	void StartSprint();
	void StopSprint();
	void StartWalk();
	void StopWalk();

	void PerformMeleeAttack();
	void StartRangedAttack();
	void StopRangedAttack();
};
