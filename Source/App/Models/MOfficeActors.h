#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MOfficeActors.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMOfficeActors : public UObject
{
	GENERATED_BODY()

public:
	UMOfficeActors();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMOfficeActors(const FVector& TargetLocation);
};
