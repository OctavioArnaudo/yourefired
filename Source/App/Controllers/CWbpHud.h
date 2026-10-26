#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CWbpHud.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCWbpHud : public UObject
{
	GENERATED_BODY()

public:
	UCWbpHud();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCWbpHud(const FVector& TargetLocation);
};
