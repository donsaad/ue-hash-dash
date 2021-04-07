// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "HashDashCharacter.h"
#include "Components/CapsuleComponent.h"
#include "AIModule\Classes\BehaviorTree\BlackboardComponent.h"
//#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "EnemyAIController.h"
//#include "Kismet\GameplayStatics.h"


// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Health = 100;
	bIsDead = false;
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (UCapsuleComponent* Capsule = GetCapsuleComponent())
	{
		Capsule->OnComponentBeginOverlap.AddDynamic(this, &AEnemyCharacter::OnEnemyBeginOverlap);
	}
	AIController = Cast<AEnemyAIController>(GetController());
	//if (AIController)
	//{
	//	BlackboardComp = UAIBlueprintHelperLibrary::GetBlackboard(AIController->GetPawn()); // cant get BB todo solve
	//}
}

void AEnemyCharacter::OnEnemyBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AHashDashCharacter* Player = Cast<AHashDashCharacter>(OtherActor))
	{
		Player->TakeDamage(1.5f);
	}

}

void AEnemyCharacter::DestroySelf()
{
	Destroy();
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!bIsDead)
	{
		if (Health < 0)
		{
			GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision); // in vain
			bIsDead = true;
			GetWorld()->GetTimerManager().SetTimer(DestroyTimerHandle, this, &AEnemyCharacter::DestroySelf, 1);
			AIController->BlackBoardComp->SetValueAsInt("CurrentEnemyCount", AIController->BlackBoardComp->GetValueAsInt("CurrentEnemyCount") - 1);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("%d"), AIController->BlackBoardComp->GetValueAsInt("CurrentEnemyCount")));
		}
	}
}

void AEnemyCharacter::TakeDamage(float Damage)
{
	Health -= Damage;
}

