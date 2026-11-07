#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "App/Models/MEnemyCharacterInstance.h"
#include "App/Views/VEnemyCharacterInstance.h"
#include "App/Services/SEnemyCharacterInstance.h"
#include "CEnemyCharacterInstance.generated.h"

class UStaticMeshComponent;

UCLASS()
class APP_API ACEnemyCharacterInstance : public ACharacter
{
	GENERATED_BODY()

public:
	ACEnemyCharacterInstance();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	MEnemyCharacterInstance EnemyModel;
	VEnemyCharacterInstance EnemyView;
	SEnemyCharacterInstance EnemyService;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* VerticalRectangleMesh;
};
