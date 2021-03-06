// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBarUserWidget.generated.h"

/**
 *
 */
UCLASS()
class HASHDASH_API UHealthBarUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UHealthBarUserWidget(const FObjectInitializer& ObjectInitializer);
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class AEnemyCharacter* EnemyCharacter;
};
