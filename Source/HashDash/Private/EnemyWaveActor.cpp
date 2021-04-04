
#include "EnemyWaveActor.h"
#include "HashDash/HashDashCharacter.h"
#include "EnemyCharacter.h"
#include "Kismet\GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AEnemyWaveActor::AEnemyWaveActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NumberOfWaves = 3;
	UnitsPerWave = 10;
	FlockingVector = FVector::ZeroVector;
	Velocity = FVector::ZeroVector;
}

// Called when the game starts or when spawned
void AEnemyWaveActor::BeginPlay()
{
	Super::BeginPlay();
	PlayerCharacter = Cast<AHashDashCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	PlayerController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	StartFirstWave();
}

// Called every frame
void AEnemyWaveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	for (int32 Index = 0; Index != EnemyArr.Num() - 1; ++Index)
	{
		if (EnemyArr[Index] && EnemyArr[Index + 1])
		{
			FlockingVector = FVector::ZeroVector;
			FVector DistToPlayer = PlayerCharacter->GetActorLocation() - EnemyArr[Index]->GetActorLocation();
			//FVector DistToOther = EnemyArr[Index + 1]->GetActorLocation() - EnemyArr[Index]->GetActorLocation();
			//FlockingVector += DistToPlayer.GetSafeNormal() + DistToOther.GetSafeNormal();
			//FlockingVector /= 2;
			FlockingVector = DistToPlayer.GetSafeNormal();
			Velocity = DeltaTime * FlockingVector * 100;
			//EnemyArr[Index]->GetActorForwardVector()* Velocity.Size();
			EnemyArr[Index]->GetCapsuleComponent()->AddImpulse(FlockingVector * 6, "", true);
		}
	}
	//FlockingVector /= EnemyArr.Num();
	//for (auto& Enemy : EnemyArr) 
	//{
	//	if (Enemy) 
	//	{
	//		Enemy->Get
	//	}
	//}
}

void AEnemyWaveActor::StartFirstWave()
{
	AEnemyCharacter* EnemyUnit;
	for (int i = 0; i < UnitsPerWave; i++)
	{
		if (EnemyToSpawn)
		{
			EnemyUnit = GetWorld()->SpawnActor<AEnemyCharacter>(EnemyToSpawn, GetActorLocation() + GetActorForwardVector() * ((i + 1) * 120), FRotator::ZeroRotator);
			if (EnemyUnit)
			{
				EnemyArr.Add(EnemyUnit);
			}
		}
	}
}

