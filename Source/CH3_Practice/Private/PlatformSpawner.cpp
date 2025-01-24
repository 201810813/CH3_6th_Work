// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformSpawner.h"
#include "DisappearPlatform.h"

// Sets default values
APlatformSpawner::APlatformSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RandY = 0.0f;
	FirstX = -803.0f;
	NextX = 0.0f;
}

void APlatformSpawner::PlatformSpawner()
{
	for (int i = 0; i < 4; ++i)
	{
		RandY = FMath::FRandRange(-510.0f, -455.0f);
		FVector SpawnLocation = FVector(FirstX+NextX, RandY,509.0f);
		FRotator SpawnRotation = FRotator(0.0f,0.0f,0.0f);
		GetWorld()->SpawnActor<ADisappearPlatform>(SpawnLocation,SpawnRotation);
		NextX += 80.0f;
	}
}

// Called when the game starts or when spawned
void APlatformSpawner::BeginPlay()
{
	Super::BeginPlay();
	PlatformSpawner();
}

// Called every frame
void APlatformSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

