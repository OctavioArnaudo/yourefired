#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MSignaturePickup.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMSignaturePickup : public UObject
{
	GENERATED_BODY()

public:
	UMSignaturePickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMSignaturePickup(const FVector& TargetLocation);
};
