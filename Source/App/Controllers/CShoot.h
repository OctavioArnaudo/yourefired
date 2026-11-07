#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "App/Models/MShoot.h"
#include "CShoot.generated.h"

UCLASS(BlueprintType, Blueprintable)
class APP_API UCShoot : public UObject
{
	GENERATED_BODY()

public:
	UCShoot();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	FString IdentifierName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controllers")
	bool bIsActive;

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	void StartFiring(UMShoot* ShootModel);

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	void StopFiring(UMShoot* ShootModel);

	UFUNCTION(BlueprintCallable, Category = "Controllers")
	bool ProcessCShoot(const FVector& TargetLocation);
};
