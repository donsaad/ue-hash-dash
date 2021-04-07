// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyWaveManager.generated.h"

UCLASS()
class HASHDASH_API AEnemyWaveManager : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyWaveManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class AEnemyWaveAIController* AIController;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
