// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class HASHDASH_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FVector Velocity;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		float Acceleration;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		float MaxSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
		float Health;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
