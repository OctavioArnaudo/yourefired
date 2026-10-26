#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPlayerFb.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCPlayerFb : public UObject
{
	GENERATED_BODY()

public:
	UCPlayerFb();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCPlayerFb(const FVector& TargetLocation);
};
