
#include "HashDashGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "HashDash/Public/GameHUD.h"

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

void AHashDashGameMode::BeginPlay()
{
	Super::BeginPlay();

	MainWidget = CreateWidget<UUserWidget>(GetWorld(), MainWidgetClass);
	if (MainWidget)
	{
		MainWidget->AddToViewport();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Widget class type was set in blueprint!"));
	}
}
