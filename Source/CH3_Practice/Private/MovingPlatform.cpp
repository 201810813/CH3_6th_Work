// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

#include "FrameTypes.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//씬 생성, 스태틱메시 부착.
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Root);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/LPGenericPropsSet04/Meshes/HouseEquipment/Ornament/SM_OrnamentSet01.SM_OrnamentSet01"));
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Steel.M_Metal_Steel"));
	if (MeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(MeshAsset.Object);
	}
	if (MaterialAsset.Succeeded())
	{
	
		StaticMesh->SetMaterial(0,MaterialAsset.Object);
	}
	
}

// void AMovingPlatform::Move(FVector RightPoint, FVector LeftPoint)
// {
// 	
// }

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	OriginLocation = GetActorLocation();
	MoveSpeed = FMath::FRandRange(1.0f,2.0f);
	MoveRange = 50.0f;
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TimeSeconds = GetWorld()->GetTimeSeconds();
	
	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		float Sind = FMath::Sin(TimeSeconds * MoveSpeed);
		if (!FMath::IsNearlyZero(MoveRange))
		{
			float move = Sind * MoveRange;
			NewLocation = OriginLocation + FVector(move,0,0);
			SetActorLocation(NewLocation);
		}
	}
}

