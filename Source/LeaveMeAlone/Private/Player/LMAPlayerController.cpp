// LeaveMeAlone Game by Artem G. All Rights Reserved.


#include "Player/LMAPlayerController.h"

ALMAPlayerController::ALMAPlayerController() 
{

}

void ALMAPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}
