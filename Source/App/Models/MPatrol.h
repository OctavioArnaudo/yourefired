#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MPatrol.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMPatrol : public UObject
{
	GENERATED_BODY()

public:
	UMPatrol();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	float PatrolRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FVector PatrolHomeLocation;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMPatrol(const FVector& TargetLocation);
};
