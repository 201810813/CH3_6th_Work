// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TimerManager.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "MovingPlatform.generated.h"


UCLASS()
class CH3_PRACTICE_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="MovingPlatform|Component")
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="MovingPlatform|Component")
	USceneComponent* Root;
	
	// UFUNCTION(BlueprintCallable, Category="Move|Function")
	// void Move(FVector RightPoint, FVector LeftPoint);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Move")
	float MoveSpeed;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Move")
	float MoveRange;

	UPROPERTY()
	float TimeSeconds;
	
	UPROPERTY()
	FVector OriginLocation;
	
	UPROPERTY()
	FVector NewLocation;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
