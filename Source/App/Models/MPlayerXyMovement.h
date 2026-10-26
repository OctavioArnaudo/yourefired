#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MPlayerXyMovement.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMPlayerXyMovement : public UObject
{
	GENERATED_BODY()

public:
	UMPlayerXyMovement();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMPlayerXyMovement(const FVector& TargetLocation);
};
