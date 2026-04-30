// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class TASK06_API AItem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItem();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly , Category = "Item|Properties")
	//float RotationSpeed; // 회전 속도
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Properties")
	float MoveSpeed; // 이동 속도
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item|Properties")
	float MaxRange; // 왕복 범위
	
	FTimerHandle TimerHandle;
	FTimerHandle DestroyTimerHandle;
	FTimerHandle MoveTimerHandle;
	void RandomMoveSpeed();
	void DestroyItem();
	void RandomMoveLocation();

	FVector StartLocation; // 시작 위치
	float TotalTime = 0.0f; // 시간 누적

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};