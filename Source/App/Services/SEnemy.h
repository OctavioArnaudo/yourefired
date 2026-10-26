#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SEnemy.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USEnemy : public UObject
{
	GENERATED_BODY()

public:
	USEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSEnemy(const FVector& TargetLocation);
};
