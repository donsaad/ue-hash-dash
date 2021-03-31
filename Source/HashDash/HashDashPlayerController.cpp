// Copyright Epic Games, Inc. All Rights Reserved.

#include "HashDashPlayerController.h"


AHashDashPlayerController::AHashDashPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AHashDashPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

}

void AHashDashPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AHashDashPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AHashDashPlayerController::OnSetDestinationReleased);

}


void AHashDashPlayerController::OnSetDestinationPressed()
{

}

void AHashDashPlayerController::OnSetDestinationReleased()
{

}
