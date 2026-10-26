#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MWbpHud.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMWbpHud : public UObject
{
	GENERATED_BODY()

public:
	UMWbpHud();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMWbpHud(const FVector& TargetLocation);
};
