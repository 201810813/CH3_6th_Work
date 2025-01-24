// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

#include "SAdvancedTransformInputBox.h"

// Sets default values
AItem::AItem()
{
	RotationSpeed = 180.0f;
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Scene);
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Scene);
	//Blueprint를 사용하지 않고 넣어줄 때. 
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Couch.SM_Couch"));
	
	if (MeshAsset.Succeeded()) {
		StaticMesh->SetStaticMesh(MeshAsset.Object);
	}
	PrimaryActorTick.bCanEverTick = true;
	
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(DeltaTime*RotationSpeed,DeltaTime*RotationSpeed,0.0f));
	}
}

void AItem::BeginPlay()
{
	
	Super::BeginPlay();
	// SetActorLocation(FVector(100, 100, 100));
	// SetActorRotation(FRotator(0.0f, 60.0f, 90.f));
	// SetActorScale3D(FVector(1.5f));
}

