
#include "HashDashGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "GameHUD.h"

AHashDashGameMode::AHashDashGameMode()
{
	//set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/HashDash/Blueprints/BP_HDCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	HUDClass = AGameHUD::StaticClass();

}

void AHashDashGameMode::EndGame()
{
	if (GameCompletedClass)
	{
		GameCompletedWidget = CreateWidget<UUserWidget>(GetWorld(), GameCompletedClass);
		if (GameCompletedWidget)
		{
			GameCompletedWidget->AddToViewport();
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Widget class type for game complete was set in game mode blueprint!"));
	}
}

void AHashDashGameMode::BeginPlay()
{
	Super::BeginPlay();

	Controller = GetWorld()->GetFirstPlayerController();
	if (Controller)
	{
		FInputModeGameOnly InputMode;
		Controller->SetInputMode(InputMode);
		Controller->bShowMouseCursor = false;
	}
	MainHudWidget = CreateWidget<UUserWidget>(GetWorld(), MainHudWidgetClass);
	if (MainHudWidget)
	{
		MainHudWidget->AddToViewport();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Widget class type was set in game mode blueprint!"));
	}
}
