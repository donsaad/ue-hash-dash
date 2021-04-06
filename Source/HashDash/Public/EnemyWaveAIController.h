// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BTTaskNode.h"
#include "EnemyWaveAIController.generated.h"

/**
 *
 */
UCLASS()
class HASHDASH_API AEnemyWaveAIController : public AAIController
{
	GENERATED_BODY()

public:

	AEnemyWaveAIController();

	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditDefaultsOnly, Category = "AIC Setup")
		UBlackboardData* BlackboardAsset;
	UPROPERTY(EditDefaultsOnly, Category = "AIC Setup")
		UBehaviorTree* BTAsset;
	UPROPERTY()
		UBlackboardComponent* BlackBoardComp;

	UPROPERTY(EditDefaultsOnly, Category = "Enemy Wave Setup")
		int32 NumberOfWaves;
	UPROPERTY(EditDefaultsOnly, Category = "Enemy Wave Setup")
		int32 EnemyUnitsPerWave;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
