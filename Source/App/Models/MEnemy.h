#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MEnemy.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMEnemy : public UObject
{
	GENERATED_BODY()

public:
	UMEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMEnemy(const FVector& TargetLocation);
};
