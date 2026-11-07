#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IShoot.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIShoot : public UObject
{
	GENERATED_BODY()

public:
	UIShoot();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIShoot(const FVector& TargetLocation);
};
