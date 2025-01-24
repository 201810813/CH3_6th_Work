// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformSpawner.generated.h"

UCLASS()
class CH3_PRACTICE_API APlatformSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformSpawner();
	UFUNCTION()
	void PlatformSpawner();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere)
	float RandY;
	UPROPERTY(VisibleAnywhere)
	float FirstX;
	UPROPERTY(VisibleAnywhere)
	float NextX;
};
