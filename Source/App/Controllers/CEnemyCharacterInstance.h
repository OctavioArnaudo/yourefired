#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "App/Models/MEnemyCharacterInstance.h"
#include "App/Views/VEnemyCharacterInstance.h"
#include "App/Services/SEnemyCharacterInstance.h"
#include "App/Controllers/CHealth.h"
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

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

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

private:
	MEnemyCharacterInstance EnemyModel;
	VEnemyCharacterInstance EnemyView;

	UPROPERTY()
	USEnemyCharacterInstance* EnemyService;

	CHealth HealthController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* VerticalRectangleMesh;
};
