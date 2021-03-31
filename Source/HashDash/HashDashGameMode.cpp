// Copyright Epic Games, Inc. All Rights Reserved.

#include "HashDashGameMode.h"
#include "HashDashPlayerController.h"
#include "HashDashCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHashDashGameMode::AHashDashGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AHashDashPlayerController::StaticClass();

#pragma region HasIssues
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/HashDash/Blueprints/BP_HDCharacter"));
	//if (PlayerPawnBPClass.Class != nullptr)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//}
#pragma endregion 

	

}