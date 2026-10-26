#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMLvl : public UObject
{
	GENERATED_BODY()

public:
	UMLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMLvl(const FVector& TargetLocation);
};
