// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class CH3_PRACTICE_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AItem();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item|Component");
	USceneComponent* Scene;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Component");
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Component");
	float RotationSpeed;
	
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	// UFUNCTION(BlueprintCallable, Category = "Item|Actions")
	// void ResetPosition();
	// UFUNCTION(BlueprintPure, Category = "Item|Property")
	// float GetRotaionSpeed() const;
};
