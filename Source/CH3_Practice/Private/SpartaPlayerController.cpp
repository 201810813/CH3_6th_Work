// Fill out your copyright notice in the Description page of Project Settings.


#include "SpartaPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "SpartaGameMode.h"


ASpartaPlayerController::ASpartaPlayerController() : InputMappingContext(nullptr),  MoveAction(nullptr), JumpAction(nullptr), LookAction(nullptr), RunAction(nullptr)
{
}


void ASpartaPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem =
			LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InputMappingContext)
			{
				SubSystem -> AddMappingContext(InputMappingContext, 0);
			}		 
		}
	}
}
