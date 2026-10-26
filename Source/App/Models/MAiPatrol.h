#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MAiPatrol.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMAiPatrol : public UObject
{
	GENERATED_BODY()

public:
	UMAiPatrol();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMAiPatrol(const FVector& TargetLocation);
};
