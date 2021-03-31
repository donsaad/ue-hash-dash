
#include "HashDashGameMode.h"
#include "HashDashCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHashDashGameMode::AHashDashGameMode()
{
#pragma region HasIssues
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/HashDash/Blueprints/BP_HDCharacter"));
	//if (PlayerPawnBPClass.Class != nullptr)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//}
#pragma endregion 

	

}