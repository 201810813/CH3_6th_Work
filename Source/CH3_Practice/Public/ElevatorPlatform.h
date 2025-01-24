// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ElevatorPlatform.generated.h"

UCLASS()
class CH3_PRACTICE_API AElevatorPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AElevatorPlatform();
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Elevator|Components")
	UStaticMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Elevator|Components")
	USceneComponent* Root;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Elevator|Movement")
	float MoveSpeed;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Elevator|Movement")
	float MoveRange;
	UPROPERTY()
	FVector OriginLocation;
	UPROPERTY()
	FVector NewLocation;
	UPROPERTY()
	float TimeSeconds;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
