#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VEnemy.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVEnemy : public UObject
{
	GENERATED_BODY()

public:
	UVEnemy();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVEnemy(const FVector& TargetLocation);
};
