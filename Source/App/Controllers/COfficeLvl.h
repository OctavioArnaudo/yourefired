#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "COfficeLvl.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCOfficeLvl : public UObject
{
	GENERATED_BODY()

public:
	UCOfficeLvl();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCOfficeLvl(const FVector& TargetLocation);
};
