// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "HashDashCharacter.h"
#include "Kismet\GameplayStatics.h"
#include "AIModule\Classes\BehaviorTree\BlackboardComponent.h"

AEnemyAIController::AEnemyAIController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	if (BlackboardAsset)
	{
		bool b = UseBlackboard(BlackboardAsset, BlackBoardComp);
		if (b)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("success BB")));

		}
		AHashDashCharacter* PlayerCharacter = Cast<AHashDashCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		BlackBoardComp->SetValueAsObject("PlayerCharacter", PlayerCharacter);
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

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

