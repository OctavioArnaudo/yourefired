#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SAiPatrol.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USAiPatrol : public UObject
{
	GENERATED_BODY()

public:
	USAiPatrol();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSAiPatrol(const FVector& TargetLocation);
};
