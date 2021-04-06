// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnBTTaskNode.h"
#include "AIModule\Classes\BehaviorTree\BlackboardComponent.h"
#include "EnemyCharacter.h"

USpawnBTTaskNode::USpawnBTTaskNode()
{

}

EBTNodeResult::Type USpawnBTTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (!ToBeSpawned)
	{
		UE_LOG(LogTemp, Error, TEXT("USpawnBTTaskNode: The class to be spawned was not found!"));
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return EBTNodeResult::Failed;
	}
	if (UBlackboardComponent* BBComp = OwnerComp.GetBlackboardComponent())
	{
		FVector SpawnLoc = BBComp->GetValueAsVector(BBSpawnLocKey.SelectedKeyName);
		GetWorld()->SpawnActor<AEnemyCharacter>(ToBeSpawned, SpawnLoc, FRotator::ZeroRotator);
		BBComp->SetValueAsInt(BBEnemyNumKey.SelectedKeyName, BBComp->GetValueAsInt(BBEnemyNumKey.SelectedKeyName) - 1);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("num: %d"), BBComp->GetValueAsInt(BBEnemyNumKey.SelectedKeyName)));
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}
	else
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
		return EBTNodeResult::Failed;
	}
}
