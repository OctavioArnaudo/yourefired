#include "WeaponBase.h"
#include "Components/StaticMeshComponent.h"

AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	WeaponType = EOfficeWeaponType::PaperAirplane;
	Damage = 15.0f;
	Durability = 5;
	bCanBeThrown = true;
}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
}

void AWeaponBase::Attack()
{
	if (Durability > 0)
	{
		Durability--;
		UE_LOG(LogTemp, Log, TEXT("Attacked with Office Weapon. Remaining durability: %d"), Durability);
		if (Durability <= 0)
		{
			UE_LOG(LogTemp, Log, TEXT("Weapon broke!"));
			Destroy();
		}
	}
}

void AWeaponBase::ThrowWeapon(FVector Direction)
{
	if (bCanBeThrown)
	{
		UE_LOG(LogTemp, Log, TEXT("Weapon thrown in direction: %s"), *Direction.ToString());
		Destroy();
	}
}
