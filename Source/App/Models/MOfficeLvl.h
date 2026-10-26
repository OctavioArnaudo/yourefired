#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MOfficeLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UMOfficeLvl : public UObject
{
	GENERATED_BODY()

public:
	UMOfficeLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Models")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Models")
	bool ProcessMOfficeLvl(const FVector& TargetLocation);
};
