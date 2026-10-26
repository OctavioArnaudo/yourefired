#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VAiPatrol.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVAiPatrol : public UObject
{
	GENERATED_BODY()

public:
	UVAiPatrol();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVAiPatrol(const FVector& TargetLocation);
};
