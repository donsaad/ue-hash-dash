// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyWaveAIController.h"
#include "AIModule\Classes\BehaviorTree\BlackboardComponent.h"

AEnemyWaveAIController::AEnemyWaveAIController()
{
	PrimaryActorTick.bCanEverTick = true;

	NumberOfWaves = 2;
	EnemyUnitsPerWave = 15;
}

void AEnemyWaveAIController::BeginPlay()
{
	Super::BeginPlay();
	if (BlackboardAsset)
	{
		UseBlackboard(BlackboardAsset, BlackBoardComp);
		BlackBoardComp->SetValueAsInt("EnemyUnitsPerWave", EnemyUnitsPerWave);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No BlackBoard Asset was set in AIC BP!"));
	}
	if (BTAsset)
	{
		RunBehaviorTree(BTAsset);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No BT Asset was set in AIC BP!"));
	}
}

void AEnemyWaveAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
