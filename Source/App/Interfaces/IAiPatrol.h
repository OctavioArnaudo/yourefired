#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IAiPatrol.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIAiPatrol : public UObject
{
	GENERATED_BODY()

public:
	UIAiPatrol();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIAiPatrol(const FVector& TargetLocation);
};
