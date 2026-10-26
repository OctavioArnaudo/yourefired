#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SOfficeLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API USOfficeLvl : public UObject
{
	GENERATED_BODY()

public:
	USOfficeLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Services")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Services")
	bool ProcessSOfficeLvl(const FVector& TargetLocation);
};
