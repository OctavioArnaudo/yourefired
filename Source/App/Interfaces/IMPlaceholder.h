#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IMPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UIMPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UIMPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interfaces")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Interfaces")
	bool ProcessIMPlaceholder(const FVector& TargetLocation);
};
