#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VPlaceholder.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVPlaceholder : public UObject
{
	GENERATED_BODY()

public:
	UVPlaceholder();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVPlaceholder(const FVector& TargetLocation);
};
