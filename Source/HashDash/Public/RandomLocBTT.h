// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "RandomLocBTT.generated.h"

/**
 * 
 */
UCLASS()
class HASHDASH_API URandomLocBTT : public UBTTaskNode
{
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere)
		float Radius;
	UPROPERTY(EditAnywhere)
		FBlackboardKeySelector OutLocKey;
};
