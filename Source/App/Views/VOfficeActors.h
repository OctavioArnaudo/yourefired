#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VOfficeActors.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVOfficeActors : public UObject
{
	GENERATED_BODY()

public:
	UVOfficeActors();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVOfficeActors(const FVector& TargetLocation);
};
