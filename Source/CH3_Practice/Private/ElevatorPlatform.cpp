// Fill out your copyright notice in the Description page of Project Settings.


#include "ElevatorPlatform.h"

#include "Net/Core/Analytics/NetStatsUtils.h"

// Sets default values
AElevatorPlatform::AElevatorPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	MeshComp->SetupAttachment(Root);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/LPGenericPropsSet04/Meshes/HouseEquipment/Ornament/SM_OrnamentSet01.SM_OrnamentSet01"));
	static ConstructorHelpers::FObjectFinder<UMaterial>	MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Steel.M_Metal_Steel"));
	if (MeshAsset.Succeeded())
	{
		MeshComp->SetStaticMesh(MeshAsset.Object);
	}
	if (MaterialAsset.Succeeded())
	{
		MeshComp->SetMaterial(0, MaterialAsset.Object);
	}
	MoveSpeed = 1.0f;
	MoveRange = 100.0f;
	
}

// Called when the game starts or when spawned
void AElevatorPlatform::BeginPlay()
{
	Super::BeginPlay();
	OriginLocation = GetActorLocation();
}

// Called every frame
void AElevatorPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TimeSeconds = GetWorld()->GetTimeSeconds();
	
	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		float Sind = FMath::Sin(TimeSeconds * MoveSpeed);
		if (!FMath::IsNearlyZero(MoveRange))
		{
			float move = Sind * MoveRange;
			NewLocation = OriginLocation + FVector(0,0,move);
			SetActorLocation(NewLocation);
		}
	}
}

