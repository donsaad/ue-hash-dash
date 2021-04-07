// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class HASHDASH_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:

	AEnemyAIController();

	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditDefaultsOnly, Category = "AIC Setup")
		UBlackboardData* BlackboardAsset;
	UPROPERTY(EditDefaultsOnly, Category = "AIC Setup")
		UBehaviorTree* BTAsset;
	UPROPERTY()
		UBlackboardComponent* BlackBoardComp;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
