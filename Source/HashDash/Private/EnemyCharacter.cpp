// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Velocity = FVector::ZeroVector;
	Acceleration = 250;
	MaxSpeed = 300;
	Health = 100;

}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Health < 0) 
	{
		Destroy();
	}
}

void AEnemyCharacter::TakeDamage(float Damage)
{
	Health -= Damage;
}

// Called to bind functionality to input
//void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//	PlayerInputComponent->BindAxis("MoveForward", this, &AEnemyCharacter::MoveForward);
//}

