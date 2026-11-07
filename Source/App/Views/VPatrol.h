#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VPatrol.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVPatrol : public UObject
{
	GENERATED_BODY()

public:
	UVPatrol();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVPatrol(const FVector& TargetLocation);
};
