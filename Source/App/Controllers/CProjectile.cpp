#include "CProjectile.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "Engine/DamageEvents.h"
#include "App/Services/SDamage.h"
#include "App/Controllers/CPlayerCharacterInstance.h"
#include "App/Controllers/CEnemyCharacterInstance.h"

ACProjectile::ACProjectile()
	: ProjectileDamage(25.0f)
	, ShooterActor(nullptr)
{
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	RootComponent = ProjectileMesh;

	ProjectileMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	ProjectileMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	ProjectileMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	ProjectileMesh->SetNotifyRigidBodyCollision(true);
	ProjectileMesh->SetGenerateOverlapEvents(true);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (SphereMeshAsset.Succeeded())
	{
		ProjectileMesh->SetStaticMesh(SphereMeshAsset.Object);
		ProjectileMesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	}

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->SetUpdatedComponent(RootComponent);
	ProjectileMovement->InitialSpeed = 2500.0f;
	ProjectileMovement->MaxSpeed = 2500.0f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.0f;

	InitialLifeSpan = 5.0f;
}

void ACProjectile::BeginPlay()
{
	Super::BeginPlay();
	if (ProjectileMovement)
	{
		ProjectileMovement->SetUpdatedComponent(RootComponent);
		ProjectileMovement->Velocity = GetActorForwardVector() * ProjectileMovement->InitialSpeed;
		ProjectileMovement->Activate();
	}
}

void ACProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!GetWorld()) return;
	FVector CurrentLoc = GetActorLocation();

	TArray<AActor*> FoundCharacters;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACharacter::StaticClass(), FoundCharacters);

	for (AActor* Actor : FoundCharacters)
	{
		if (IsValid(Actor) && Actor != this && Actor != ShooterActor && Actor != GetOwner())
		{
			float Dist = FVector::Dist(CurrentLoc, Actor->GetActorLocation());
			if (Dist <= 120.0f)
			{
				UE_LOG(LogTemp, Warning, TEXT("[ACProjectile] Proximity impact with '%s' at dist %.1f!"), *Actor->GetName(), Dist);
				ProcessHit(Actor);
				break;
			}
		}
	}
}

void ACProjectile::OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ProcessHit(OtherActor);
}

void ACProjectile::OnProjectileOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ProcessHit(OtherActor);
}

void ACProjectile::ProcessHit(AActor* OtherActor)
{
	if (IsValid(OtherActor) && OtherActor != this && OtherActor != ShooterActor && OtherActor != GetOwner())
	{
		UE_LOG(LogTemp, Warning, TEXT("[ACProjectile] PROJECTILE HIT '%s' (Class: %s)! Applying %.2f damage."),
			*OtherActor->GetName(), *OtherActor->GetClass()->GetName(), ProjectileDamage);

		USDamage::ApplyDamageUniversal(OtherActor, ProjectileDamage, GetInstigatorController(), this);
		Destroy();
	}
}
