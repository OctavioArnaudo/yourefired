#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IWeapon.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIWeapon : public UObject
{
	GENERATED_BODY()

public:
	UIWeapon();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIWeapon(const FVector& TargetLocation);
};
