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

	FTimerHandle DestroyTimerHandle;

	/* UPROPERTIES */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
		float Health;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
		bool bIsDead;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
		float HealthPercentage;

	UFUNCTION(BlueprintCallable)
		void OnEnemyBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void DestroySelf();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void TakeDamage(float Damage);
	class AEnemyAIController* AIController;
	//class UBlackboardComponent* BlackboardComp;
	class UWidgetComponent* HealthWidgetComp;
	class UHealthBarUserWidget* HealthBarUI;
};
