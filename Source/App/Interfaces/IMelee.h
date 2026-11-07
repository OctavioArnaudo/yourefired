#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IMelee.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIMelee : public UObject
{
	GENERATED_BODY()

public:
	UIMelee();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIMelee(const FVector& TargetLocation);
};
