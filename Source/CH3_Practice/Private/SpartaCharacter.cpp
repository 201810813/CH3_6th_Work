// Fill out your copyright notice in the Description page of Project Settings.
#include "SpartaCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "SpartaPlayerController.h"
#include "Camera/CameraComponent.h"
#include "NavigationSystemTypes.h"


ASpartaCharacter::ASpartaCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	SpringArmCom = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmCom->SetupAttachment(RootComponent);
	SpringArmCom->TargetArmLength = 30.0f;
	SpringArmCom->bUsePawnControlRotation = true;
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmCom, USpringArmComponent::SocketName);
	CameraComp->bUsePawnControlRotation = false;

	NormalSpeed = 60.0f;
	RunningMultiplier = 1.5f;
	RunningSpeed = NormalSpeed * RunningMultiplier;
	GetCharacterMovement()->JumpZVelocity = 320.0f;
	GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
}
void ASpartaCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}
void ASpartaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ASpartaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhacedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (ASpartaPlayerController* PlayerController = Cast<ASpartaPlayerController>(GetController()))
		{
			if (PlayerController->MoveAction)
			{
				EnhacedInput->BindAction(
					PlayerController->MoveAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::Move
				);
			}
			if (PlayerController->JumpAction)
			{
				EnhacedInput->BindAction(
					PlayerController->JumpAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::StartJump
				);
				
				EnhacedInput->BindAction(
					PlayerController->JumpAction,
					ETriggerEvent::Completed,
					this,
					&ASpartaCharacter::StopJump
				);
				
			}
			if (PlayerController->LookAction)
			{
				EnhacedInput->BindAction(
					PlayerController->LookAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::Look
				);
			}
			if (PlayerController->RunAction)
			{
				EnhacedInput->BindAction(
					PlayerController->RunAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::StartRun
				);
				EnhacedInput->BindAction(
					PlayerController->RunAction,
					ETriggerEvent::Completed,
					this,
					&ASpartaCharacter::StopRun
				);
			}
			
		}
	}

}

void ASpartaCharacter::Move(const FInputActionValue& Value)
{
	if (!Controller) return;
	const FVector2d MoveInput = Value.Get<FVector2d>();
	if (!FMath::IsNearlyZero(MoveInput.X))
	{
		AddMovementInput(GetActorForwardVector(),MoveInput.X);
	}
	if (!FMath::IsNearlyZero(MoveInput.Y))
	{
		AddMovementInput(GetActorRightVector(),MoveInput.Y);
	}
}
void ASpartaCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookInput = Value.Get<FVector2d>();
	AddControllerYawInput(LookInput.X);
	AddControllerPitchInput(LookInput.Y);
}
void ASpartaCharacter::StartJump(const FInputActionValue& Value)
{
	if (Value.Get<bool>())
	{
		Jump();
	}
}
void ASpartaCharacter::StopJump(const FInputActionValue& Value)
{
	if (!Value.Get<bool>())
	{
		StopJumping();
	}	
}
void ASpartaCharacter::StartRun(const FInputActionValue& Value)
{
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = RunningSpeed;
	}
	
}
void ASpartaCharacter::StopRun(const FInputActionValue& Value)
{
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
	}
}
