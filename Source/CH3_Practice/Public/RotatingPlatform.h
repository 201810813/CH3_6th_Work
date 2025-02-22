// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class CH3_PRACTICE_API ARotatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotatingPlatform();
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="MovingPlatform|Component")
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="MovingPlatform|Component")
	USceneComponent* Root;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="MovingPlatform|Rotate")
	float RotateSpeed;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
