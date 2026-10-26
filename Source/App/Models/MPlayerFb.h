#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MPlayerFb.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMPlayerFb : public UObject
{
	GENERATED_BODY()

public:
	UMPlayerFb();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMPlayerFb(const FVector& TargetLocation);
};
