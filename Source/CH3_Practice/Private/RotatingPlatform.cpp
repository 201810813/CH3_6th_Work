// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingPlatform.h"

// Sets default values
ARotatingPlatform::ARotatingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);
	StaticMesh->SetupAttachment(Root);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/LPGenericPropsSet04/Meshes/HouseEquipment/Bunk/SM_BunkSet03Fabric.SM_BunkSet03Fabric"));
	if (MeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(MeshAsset.Object);
	}
	SetActorScale3D(FVector(0.3f,0.3f,0.2f));

}

// Called when the game starts or when spawned
void ARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	RotateSpeed = FMath::FRandRange(50.0f,100.0f);
}

// Called every frame
void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotateSpeed))
	{
		AddActorLocalRotation(FRotator(0, RotateSpeed*DeltaTime, 0));
	}
}

