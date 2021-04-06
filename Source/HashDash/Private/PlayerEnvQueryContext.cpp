// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerEnvQueryContext.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"

void UPlayerEnvQueryContext::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	AActor* QueryOwner = Cast<AActor>(QueryInstance.Owner.Get());
	if (QueryOwner)
	{
		UEnvQueryItemType_Actor::SetContextHelper(ContextData, QueryOwner->GetWorld()->GetFirstPlayerController()->GetPawn());
	}
}
