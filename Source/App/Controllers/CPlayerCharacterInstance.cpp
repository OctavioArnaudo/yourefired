#include "CPlayerCharacterInstance.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "UObject/ConstructorHelpers.h"

ACPlayerCharacterInstance::ACPlayerCharacterInstance()
{
	PrimaryActorTick.bCanEverTick = true;

	WalkSpeed = 400.0f;
	SprintSpeed = 750.0f;
	bIsSprinting = false;
	RangedSpawnOffset = 100.0f;

	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
		GetCharacterMovement()->bOrientRotationToMovement = false;
		GetCharacterMovement()->bConstrainToPlane = true;
		GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0.0f, 0.0f, 1.0f));
	}

	bUseControllerRotationYaw = false;

	VerticalRectangleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VerticalRectangleMesh"));
	VerticalRectangleMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeMeshAsset.Succeeded())
	{
		VerticalRectangleMesh->SetStaticMesh(CubeMeshAsset.Object);
		VerticalRectangleMesh->SetRelativeScale3D(FVector(0.8f, 0.8f, 2.0f));
	}

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->TargetArmLength = 1200.0f;
	CameraBoom->SetRelativeRotation(FRotator(-55.0f, 0.0f, 0.0f));
	CameraBoom->bDoCollisionTest = false;

	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCameraComponent"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false;
}

void ACPlayerCharacterInstance::BeginPlay()
{
	Super::BeginPlay();
}

void ACPlayerCharacterInstance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotateTowardsCursor();
}

void ACPlayerCharacterInstance::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayerCharacterInstance::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPlayerCharacterInstance::MoveRight);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ACPlayerCharacterInstance::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ACPlayerCharacterInstance::StopSprint);

	PlayerInputComponent->BindAction("MeleeAttack", IE_Pressed, this, &ACPlayerCharacterInstance::PerformMeleeAttack);
	PlayerInputComponent->BindAction("RangedAttack", IE_Pressed, this, &ACPlayerCharacterInstance::PerformRangedAttack);
}

void ACPlayerCharacterInstance::MoveForward(float Value)
{
	if (Controller && Value != 0.0f)
	{
		AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
	}
}

void ACPlayerCharacterInstance::MoveRight(float Value)
{
	if (Controller && Value != 0.0f)
	{
		AddMovementInput(FVector(0.0f, 1.0f, 0.0f), Value);
	}
}

void ACPlayerCharacterInstance::StartSprint()
{
	bIsSprinting = true;
	if (GetCharacterMovement()) GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void ACPlayerCharacterInstance::StopSprint()
{
	bIsSprinting = false;
	if (GetCharacterMovement()) GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void ACPlayerCharacterInstance::RotateTowardsCursor()
{
	APlayerController* PC = Cast<APlayerController>(GetController());
	if (!PC) return;

	FHitResult HitResult;
	PC->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);

	if (HitResult.bBlockingHit)
	{
		FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), HitResult.ImpactPoint);
		FRotator NewRotation(0.0f, TargetRotation.Yaw, 0.0f);
		SetActorRotation(NewRotation);
	}
}

void ACPlayerCharacterInstance::PerformMeleeAttack()
{
	UE_LOG(LogTemp, Log, TEXT("¡Ataque Melee ejecutado hacia el cursor!"));
}

void ACPlayerCharacterInstance::PerformRangedAttack()
{
	if (!ProjectileClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("¡No hay ProjectileClass asignada en el Blueprint del personaje!"));
		return;
	}

	FVector SpawnLocation = GetActorLocation() + (GetActorForwardVector() * RangedSpawnOffset);
	FRotator SpawnRotation = GetActorRotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = this;

	AActor* SpawnedProjectile = GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);

	if (SpawnedProjectile)
	{
		UE_LOG(LogTemp, Log, TEXT("¡Proyectil a distancia spawneado con éxito!"));
	}
}
