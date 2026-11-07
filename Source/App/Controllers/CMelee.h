#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CMelee.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCMelee : public UObject
{
	GENERATED_BODY()

public:
	UCMelee();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCMelee(const FVector& TargetLocation);
};
