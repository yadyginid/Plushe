// Copyright Epic Games, Inc. All Rights Reserved.

#include "PlusheGameMode.h"
#include "PlusheCharacter.h"
#include "UObject/ConstructorHelpers.h"

APlusheGameMode::APlusheGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
