
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HashDashGameMode.generated.h"

UCLASS(minimalapi)
class AHashDashGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AHashDashGameMode();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUD")
	TSubclassOf<class UUserWidget> MainWidgetClass;
	UUserWidget* MainWidget;

protected:
	virtual void BeginPlay() override;

};



