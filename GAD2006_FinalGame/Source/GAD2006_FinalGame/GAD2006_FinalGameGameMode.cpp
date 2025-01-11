// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAD2006_FinalGameGameMode.h"
#include "GAD2006_FinalGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGAD2006_FinalGameGameMode::AGAD2006_FinalGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
