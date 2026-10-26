#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MDoor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMDoor : public UObject
{
	GENERATED_BODY()

public:
	UMDoor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMDoor(const FVector& TargetLocation);
};
