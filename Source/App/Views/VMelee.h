#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VMelee.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVMelee : public UObject
{
	GENERATED_BODY()

public:
	UVMelee();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVMelee(const FVector& TargetLocation);
};
