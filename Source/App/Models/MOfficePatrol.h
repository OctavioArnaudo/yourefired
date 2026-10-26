#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MOfficePatrol.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMOfficePatrol : public UObject
{
	GENERATED_BODY()

public:
	UMOfficePatrol();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMOfficePatrol(const FVector& TargetLocation);
};
