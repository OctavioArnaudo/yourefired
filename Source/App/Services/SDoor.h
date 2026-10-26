#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDoor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USDoor : public UObject
{
	GENERATED_BODY()

public:
	USDoor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSDoor(const FVector& TargetLocation);
};
