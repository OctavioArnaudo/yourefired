#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MSupervisorEnemy.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMSupervisorEnemy : public UObject
{
	GENERATED_BODY()

public:
	UMSupervisorEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMSupervisorEnemy(const FVector& TargetLocation);
};
