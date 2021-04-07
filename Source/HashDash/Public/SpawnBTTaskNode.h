// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SpawnBTTaskNode.generated.h"

/**
 * Spawns "AEnemyCharacter" based on a blackboard location set by another task 
 */
UCLASS()
class HASHDASH_API USpawnBTTaskNode : public UBTTaskNode
{
	GENERATED_BODY()

public:

	USpawnBTTaskNode();

protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere)
		FBlackboardKeySelector BBSpawnLocKey;
	UPROPERTY(EditAnywhere)
		FBlackboardKeySelector BBEnemyPerWaveKey;
	UPROPERTY(EditAnywhere)
		FBlackboardKeySelector BBCurrEnemyNumKey;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AEnemyCharacter> ToBeSpawned;
};
