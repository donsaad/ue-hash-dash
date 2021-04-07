
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
	TSubclassOf<class UUserWidget> MainHudWidgetClass;
	UUserWidget* MainHudWidget;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HUD")
	TSubclassOf<class UUserWidget> GameCompletedClass;
	UUserWidget* GameCompletedWidget;

	void EndGame();
protected:
	virtual void BeginPlay() override;
	APlayerController* Controller;
};



