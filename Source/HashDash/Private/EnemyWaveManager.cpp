// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyWaveManager.h"
#include "EnemyWaveAIController.h"
#include "Kismet\GameplayStatics.h"
#include "EnemyCharacter.h"
#include "EnemyWaveAIController.h"
#include "AIModule\Classes\BehaviorTree\BlackboardComponent.h"
#include "HashDashGameMode.h"

// Sets default values
AEnemyWaveManager::AEnemyWaveManager()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyWaveManager::BeginPlay()
{
	Super::BeginPlay();
	AIController = Cast<AEnemyWaveAIController>(GetController());
}

// Called every frame
void AEnemyWaveManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//if (AIController->BlackBoardComp->GetValueAsInt("CurrentEnemyCount") == 0 
	//	&& AIController->BlackBoardComp->GetValueAsInt("EnemyUnitsPerWave") == 0)
	//{
	//	AIController->BlackBoardComp->SetValueAsInt("EnemyWaves", 1);
	//	AIController->BlackBoardComp->SetValueAsInt("EnemyUnitsPerWave", 15);
	//	AHashDashGameMode* GameMode = Cast<AHashDashGameMode>(GetWorld()->GetAuthGameMode());
	//	GameMode->EndGame();
	//}

}

