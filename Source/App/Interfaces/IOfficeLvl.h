#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IOfficeLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIOfficeLvl : public UObject
{
	GENERATED_BODY()

public:
	UIOfficeLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIOfficeLvl(const FVector& TargetLocation);
};
