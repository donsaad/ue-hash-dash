
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
	DirToPlayer = FVector::ZeroVector;
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

	//for (int32 Index = 0; Index != EnemyArr.Num(); ++Index)
	//{
	//	if (EnemyArr[Index])
	//	{
	//		DirToPlayer = FVector::ZeroVector;
	//		FVector DistToPlayer = PlayerCharacter->GetActorLocation() - EnemyArr[Index]->GetActorLocation();
	//		FVector DistToOther = EnemyArr[Index + 1]->GetActorLocation() - EnemyArr[Index]->GetActorLocation();
	//		FlockingVector += DistToPlayer.GetSafeNormal() + DistToOther.GetSafeNormal();
	//		FlockingVector /= 2;
	//		DirToPlayer = DistToPlayer.GetSafeNormal();
	//		Velocity = DeltaTime * FlockingVector * 100;
	//		EnemyArr[Index]->GetActorForwardVector()* Velocity.Size();
	//		EnemyArr[Index]->GetCapsuleComponent()->AddImpulse(DirToPlayer * 1000 * DeltaTime, "", true);
	//		if (AController* Acont = EnemyArr[Index]->Controller)
	//		{
	//			FRotator YawRotation(0, Acont->GetControlRotation().Yaw, 0);
	//			EnemyArr[Index]->SetActorRotation(YawRotation);
	//			UE_LOG(LogTemp, Warning, TEXT("rot"));
	//		}
	//	}
	//}
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

