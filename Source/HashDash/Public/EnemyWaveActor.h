
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyWaveActor.generated.h"

UCLASS()
class HASHDASH_API AEnemyWaveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyWaveActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, Category = "Enemy Wave Options")
		int32 NumberOfWaves;
	UPROPERTY(EditDefaultsOnly, Category = "Enemy Wave Options")
		int32 UnitsPerWave;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy Wave Options")
		TSubclassOf<class AEnemyCharacter> EnemyToSpawn;

	TArray<class AEnemyCharacter*> EnemyArr;
	FVector DirToPlayer;
	FVector Velocity;
	class AHashDashCharacter* PlayerCharacter;
	class APlayerController* PlayerController;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void StartFirstWave();
};
