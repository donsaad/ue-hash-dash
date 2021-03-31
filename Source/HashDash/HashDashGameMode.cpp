// Copyright Epic Games, Inc. All Rights Reserved.

#include "HashDashGameMode.h"
#include "HashDashPlayerController.h"
#include "HashDashCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHashDashGameMode::AHashDashGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AHashDashPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}