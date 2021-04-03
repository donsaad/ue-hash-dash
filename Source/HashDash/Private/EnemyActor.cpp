
#include "EnemyActor.h"
//#include "Components/SkeletalMeshComponent.h"

// Sets default values
AEnemyActor::AEnemyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Velocity = FVector::ZeroVector;
	Acceleration = 250;
	MaxSpeed = 300;
}

// Called when the game starts or when spawned
void AEnemyActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Velocity += GetActorForwardVector() * DeltaTime * Acceleration;

	if (Velocity.Size() > MaxSpeed) 
	{
		Velocity = Velocity.GetSafeNormal() * MaxSpeed;
	}

	SetActorLocation(GetActorLocation() + Velocity * DeltaTime);

}

