// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

// Sets default values
AItem::AItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//RotationSpeed = 90.0f;
	MoveSpeed = 10.0f;
	MaxRange = 100.0f;
}

void AItem::RandomMoveSpeed()
{
	// 이동 속도 랜덤
	MoveSpeed = FMath::FRandRange(0.1f, 2.0f);
}

void AItem::DestroyItem()
{
	Destroy();
}

void AItem::RandomMoveLocation()
{
	//FVector NewLocation = StartLocation;
	StartLocation.X += FMath::FRandRange(-MaxRange, MaxRange);
	StartLocation.Y += FMath::FRandRange(-MaxRange, MaxRange);
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AItem::RandomMoveSpeed, 2.0f, true);
	//GetWorld()->GetTimerManager().SetTimer(DestroyTimerHandle, this, &AItem::DestroyItem, 5.0f, false);
	//GetWorld()->GetTimerManager().SetTimer(MoveTimerHandle, this, &AItem::RandomMoveLocation, 3.0f, true);
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	TotalTime += DeltaTime * MoveSpeed;

	//float Delta = MaxRange * FMath::Sin(TotalTime);
	//float Delta = MaxRange * FMath::Sin(TotalTime) * MoveSpeed;
	float Delta = MaxRange * FMath::Sin(TotalTime);
	FVector NewLocation = StartLocation;
	NewLocation.Y = Delta;
	SetActorLocation(NewLocation);

	//GetWorld()->SpawnActor<AItem>(AItem::StaticClass(), GetActorLocation(), GetActorRotation());
}
