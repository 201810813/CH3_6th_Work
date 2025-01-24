// Fill out your copyright notice in the Description page of Project Settings.
#include "SpartaGameMode.h"
#include "SpartaCharacter.h"
#include "SpartaPlayerController.h"
#include "DisappearPlatform.h"

ASpartaGameMode::ASpartaGameMode()
{
	DefaultPawnClass = ASpartaCharacter::StaticClass();
	PlayerControllerClass = ASpartaPlayerController::StaticClass();
}


