// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "DisappearPlatform.generated.h"

UCLASS()
class CH3_PRACTICE_API ADisappearPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADisappearPlatform();

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="MovingPlatform|Component")
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="MovingPlatform|Component")
	USceneComponent* Root;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FTimerHandle DisappearTimer;
	FTimerHandle ShowTimer;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="MovingPlatform|Disappear")
	float DisappearTime;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="MovingPlatform|Disappear")
	float ShowTime;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void DisappearActor();
	void ShowActor();
};
