// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomLocBTT.h"
#include "NavigationSystem/Public/NavigationSystem.h"
#include "AIModule\Classes\AIController.h"
#include "AIModule\Classes\BehaviorTree\BlackboardComponent.h"

EBTNodeResult::Type URandomLocBTT::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AAIController* AIController = OwnerComp.GetAIOwner())
	{
		if (APawn* OurPawn = AIController->GetPawn())
		{
			UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(OwnerComp.GetWorld());
			if (NavSys)
			{
				ANavigationData* UseNavData = NavSys->GetDefaultNavDataInstance(FNavigationSystem::DontCreate);
				if (UseNavData)
				{
					FNavLocation OutNavLoc;
					if (NavSys->GetRandomPointInNavigableRadius(OurPawn->GetActorLocation(), Radius, OutNavLoc, UseNavData, NavSys->CreateDefaultQueryFilterCopy()))
					{
						if (UBlackboardComponent* BBComp = OwnerComp.GetBlackboardComponent())
						{
							BBComp->SetValueAsVector(OutLocKey.SelectedKeyName, OutNavLoc.Location);
							FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
							return EBTNodeResult::Succeeded;
						}
					}
				}
			}
		}
	}
	FinishLatentTask(OwnerComp, EBTNodeResult::Failed);
	return EBTNodeResult::Failed;
}
