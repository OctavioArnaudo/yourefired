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
	USSpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* TopDownCameraComponent;

	bool bIsRangedAttacking;

	void MoveForward(float Value);
	void MoveRight(float Value);

	void StartSprint();
	void StopSprint();

	void PerformMeleeAttack();
	void StartRangedAttack();
	void StopRangedAttack();
};
