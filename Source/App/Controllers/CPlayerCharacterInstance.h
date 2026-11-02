#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "App/Models/MPlayerCharacterInstance.h"
#include "App/Views/VPlayerCharacterInstance.h"
#include "App/Services/SPlayerCharacterInstance.h"
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
	MPlayerCharacterInstance PlayerModel;
	VPlayerCharacterInstance PlayerView;
	SPlayerCharacterInstance PlayerService;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* VerticalRectangleMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* TopDownCameraComponent;

	void MoveForward(float Value);
	void MoveRight(float Value);

	void StartSprint();
	void StopSprint();

	void PerformMeleeAttack();
	void PerformRangedAttack();
};
