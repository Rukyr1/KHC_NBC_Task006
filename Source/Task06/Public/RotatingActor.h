// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

UCLASS()
class TASK06_API ARotatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingActor();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RotatingActor|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatingActor|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "RotatingActor|Properties")
	float RotationSpeed; // 회전 속도;

	UFUNCTION(BlueprintPure, Category = "RotatingActor|Properties")
	float GetRotationspeed() const;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
