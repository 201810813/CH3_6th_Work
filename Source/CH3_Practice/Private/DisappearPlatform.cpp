// Fill out your copyright notice in the Description page of Project Settings.


#include "DisappearPlatform.h"

// Sets default values
ADisappearPlatform::ADisappearPlatform()
{
 	//컴포넌트 생성 및 부착
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(Root);
	//에셋 생성 및 적용
	Root->SetWorldScale3D(FVector(0.1f,0.2f,0.3f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/LPGenericPropsSet04/Meshes/HouseEquipment/Bunk/SM_BunkSet03Fabric.SM_BunkSet03Fabric"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstance> MaterialAsset(TEXT("/Game/LPGenericPropsSet04/Materials/Bricks/MI_BricksSet05.MI_BricksSet05"));
	
	if (MeshAsset.Succeeded())
	{
		StaticMesh->SetStaticMesh(MeshAsset.Object);
	}
	if (MaterialAsset.Succeeded())
	{
		StaticMesh->SetMaterial(0, MaterialAsset.Object);
	}
	FTimerHandle TimerHandle;

	DisappearTime = FMath::FRandRange(5.0f, 8.0f);
	ShowTime = FMath::FRandRange(1.0f, 2.0f);
	//타이머 핸들 선언
}

// Called when the game starts or when spawned
void ADisappearPlatform::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(DisappearTimer,this, &ADisappearPlatform::DisappearActor, DisappearTime,false);
}

// Called every frame
void ADisappearPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADisappearPlatform::DisappearActor()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);

	GetWorld()->GetTimerManager().SetTimer(ShowTimer,this,&ADisappearPlatform::ShowActor, ShowTime,false);
}

void ADisappearPlatform::ShowActor()
{
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);

	GetWorld()->GetTimerManager().SetTimer(DisappearTimer,this, &ADisappearPlatform::DisappearActor, DisappearTime,false);
}

