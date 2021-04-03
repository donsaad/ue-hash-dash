
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyActor.generated.h"

UCLASS()
class HASHDASH_API AEnemyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FVector Velocity;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		float Acceleration;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
		float MaxSpeed;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
