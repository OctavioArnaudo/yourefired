#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDamage.generated.h"

class AActor;
class AController;

UCLASS(BlueprintType, Blueprintable)
class APP_API USDamage : public UObject
{
	GENERATED_BODY()

public:
	USDamage();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSDamage(const FVector& TargetLocation);

	UFUNCTION(BlueprintCallable, Category = "Services")
	static void ApplyDamageUniversal(AActor* Target, float DamageAmount, AController* EventInstigator, AActor* DamageCauser);
};
