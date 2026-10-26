#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CAiPatrol.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCAiPatrol : public UObject
{
	GENERATED_BODY()

public:
	UCAiPatrol();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCAiPatrol(const FVector& TargetLocation);
};
