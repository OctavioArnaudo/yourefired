#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MPlayerActor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMPlayerActor : public UObject
{
	GENERATED_BODY()

public:
	UMPlayerActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMPlayerActor(const FVector& TargetLocation);
};
