// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpartaCharacter.generated.h"

struct FInputActionValue;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class CH3_PRACTICE_API ASpartaCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASpartaCharacter();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera");
	USpringArmComponent* SpringArmCom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera");
	UCameraComponent* CameraComp;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void Move(const FInputActionValue& Value);
	UFUNCTION()
	void Look(const FInputActionValue& Value);
	UFUNCTION()
	void StartJump(const FInputActionValue& Value);
	UFUNCTION()
	void StopJump(const FInputActionValue& Value);
	UFUNCTION()
	void StartRun(const FInputActionValue& Value);
	UFUNCTION()
	void StopRun(const FInputActionValue& Value);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float NormalSpeed;
	float RunningSpeed;
	float RunningMultiplier;
};


