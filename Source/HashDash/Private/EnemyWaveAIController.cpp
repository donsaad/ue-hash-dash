// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyWaveAIController.h"
#include "AIModule\Classes\BehaviorTree\BlackboardComponent.h"
#include "Kismet\GameplayStatics.h"
#include "EnemyCharacter.h"


/*
*	Worst Class Logic Ever!!
*/
AEnemyWaveAIController::AEnemyWaveAIController()
{
	PrimaryActorTick.bCanEverTick = true;

	NumberOfWaves = 2;
	NumOfEnemiesToSpawn = 15;
}

void AEnemyWaveAIController::BeginPlay()
{
	Super::BeginPlay();
	if (BlackboardAsset)
	{
		UseBlackboard(BlackboardAsset, BlackBoardComp);
		BlackBoardComp->SetValueAsInt("EnemyUnitsPerWave", NumOfEnemiesToSpawn); // WTF
		BlackBoardComp->SetValueAsInt("EnemyWaves", NumberOfWaves);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No BlackBoard Asset was set in WaveAIC BP!"));
	}
	if (BTAsset)
	{
		RunBehaviorTree(BTAsset);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No BT Asset was set in WaveAIC BP!"));
	}
}

void AEnemyWaveAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
