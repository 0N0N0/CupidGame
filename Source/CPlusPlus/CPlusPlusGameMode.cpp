// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPlusPlusGameMode.h"
#include "CPlusPlusCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACPlusPlusGameMode::ACPlusPlusGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
