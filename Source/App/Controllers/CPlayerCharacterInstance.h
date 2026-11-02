#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPlayerCharacterInstance.generated.h"

class UCameraComponent;
class USpringArmComponent;
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
	// --- COMPONENTES ---

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* VerticalRectangleMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* TopDownCameraComponent;

	// --- MOVIMIENTO Y ATRIBUTOS ---

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float WalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float SprintSpeed;

	bool bIsSprinting;

	// --- COMBATE Y PROYECTILES ---

	UPROPERTY(EditDefaultsOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float RangedSpawnOffset;

	// --- FUNCIONES INTERNAS ---

	void MoveForward(float Value);
	void MoveRight(float Value);

	void StartSprint();
	void StopSprint();

	void PerformMeleeAttack();
	void PerformRangedAttack();

	void RotateTowardsCursor();
};
