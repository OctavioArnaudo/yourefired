#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VOfficePatrol.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVOfficePatrol : public UObject
{
	GENERATED_BODY()

public:
	UVOfficePatrol();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVOfficePatrol(const FVector& TargetLocation);
};
