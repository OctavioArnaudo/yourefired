#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SUaLoader.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USUaLoader : public UObject
{
	GENERATED_BODY()

public:
	USUaLoader();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSUaLoader(const FVector& TargetLocation);
};
