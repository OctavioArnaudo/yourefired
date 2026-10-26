#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MPlayerMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMPlayerMovement : public UObject
{
	GENERATED_BODY()

public:
	UMPlayerMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMPlayerMovement(const FVector& TargetLocation);
};
