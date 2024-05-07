// Copyright Epic Games, Inc. All Rights Reserved.

#include "LootexampleGameMode.h"
#include "LootexampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALootexampleGameMode::ALootexampleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
