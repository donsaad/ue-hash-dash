
#include "HashDashCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnemyCharacter.h"

AHashDashCharacter::AHashDashCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f); // was ist das?? // TODO: know  what is this?

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 1000.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	HDCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("HDCamera"));
	HDCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	HDCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	/* Use mouse rotation as input instead of WASD */
	bUseMouseRot = false;
	DashPower = 4000;
	/* Init player health attributes */
	Health = 100;
	MaxHealth = 120;
}

void AHashDashCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	/* Binding Movement Axis */
	PlayerInputComponent->BindAxis("MoveRight", this, &AHashDashCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &AHashDashCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Yaw", this, &AHashDashCharacter::Yaw);

	/* Binding Player Actions */
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AHashDashCharacter::Attack);
	PlayerInputComponent->BindAction("Dash", IE_Pressed, this, &AHashDashCharacter::Dash);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
}

void AHashDashCharacter::BeginPlay()
{
	Super::BeginPlay();

	//	UStaticMeshComponent* Weapon = FindComponentByClass<UStaticMeshComponent>();
	//if (Weapon)
	//{
	//	Weapon->OnComponentBeginOverlap.AddDynamic(this, &AHashDashCharacter::OnWeaponBeginOverlap);
	//}
}

void AHashDashCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	DeltaTime = DeltaSeconds;
	if (bUseMouseRot)
	{
		SetMouseRotationInput();
	}
}

void AHashDashCharacter::TakeDamage(float Damage)
{
	Health -= Damage;
	UE_LOG(LogTemp, Warning, TEXT("player is hit"));
}

void AHashDashCharacter::MoveRight(float Value)
{
	// If not using mouse Rot dont add horizontal input
	if (!bIsAttacking && !bUseMouseRot && (Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);
		AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y), Value);
	}
}

void AHashDashCharacter::MoveForward(float Value)
{
	if (!bIsAttacking && (Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);
		AddMovementInput(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X), Value);
	}
}

void AHashDashCharacter::Yaw(float Value)
{
	if (bUseMouseRot)
	{
		AddControllerYawInput(Value);
	}
}

void AHashDashCharacter::Attack()
{
	bIsAttacking = true;
}

void AHashDashCharacter::Dash()
{
	GetCharacterMovement()->AddImpulse(GetActorForwardVector() * DashPower, true);
}

void AHashDashCharacter::OnWeaponBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// only apply damage while attacking 
	if (!bIsAttacking)
		return;
	AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(OtherActor);
	if (Enemy)
	{
		Enemy->TakeDamage(25);
		UE_LOG(LogTemp, Warning, TEXT("enemy took damage"));
	}
}

void AHashDashCharacter::SetMouseRotationInput()
{
	FRotator ActorRot = GetActorRotation();
	ActorRot.Yaw = GetControlRotation().Yaw;
	SetActorRotation(ActorRot);
}

