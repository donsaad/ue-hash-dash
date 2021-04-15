

#include "EnemyCharacter.h"
#include "HashDashCharacter.h"
#include "Components/CapsuleComponent.h"
#include "AIModule\Classes\BehaviorTree\BlackboardComponent.h"
#include "EnemyWaveManager.h"
#include "EnemyWaveAIController.h"
#include "Kismet\GameplayStatics.h"
#include "Components\WidgetComponent.h"
#include "HealthBarUserWidget.h"


// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	Health = 100;
	HealthPercentage = 100;
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
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyWaveManager::StaticClass(), OutActors);


	if (OutActors.Num() > 0)
	{
		APawn* WaveManager = Cast<AEnemyWaveManager>(OutActors[0]);
		if (WaveManager)
		{
			AIController = Cast<AEnemyWaveAIController>(WaveManager->GetController());
		}
		//else {
		//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("cant cast pawn")));
		//}
	}
	//if (AIController)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("got it")));
	//}

	//if (AIController)
	//{
	//	BlackboardComp = UAIBlueprintHelperLibrary::GetBlackboard(AIController->GetPawn()); // cant get BB todo solve
	//}
	HealthWidgetComp = FindComponentByClass<UWidgetComponent>();
	if (HealthWidgetComp)
	{
		HealthBarUI = Cast<UHealthBarUserWidget>(HealthWidgetComp->GetUserWidgetObject());
		if (HealthBarUI)
		{
			HealthBarUI->EnemyCharacter = this;
		}
	}
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
			//GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision); // in vain
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
	HealthPercentage = Health / 100;
}

