#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VOfficeLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UVOfficeLvl : public UObject
{
	GENERATED_BODY()

public:
	UVOfficeLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Views")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Views")
	bool ProcessVOfficeLvl(const FVector& TargetLocation);
};
