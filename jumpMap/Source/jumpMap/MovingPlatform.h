// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class JUMPMAP_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MovingPlatform(float DeltaTime);
	void RotationPlatform(float DeltaTime);

	float GetDistanceMoved();

	UPROPERTY(EditAnywhere)
	FVector PlatformVelocity = FVector(0.f, 0.f, 0.f);

	UPROPERTY(EditAnywhere)
	float MoveDistance = 100.f;

	UPROPERTY(VisibleAnywhere)
	float DistanceMoved = 0.f;

	FVector StartLocation;

	UPROPERTY(EditAnywhere)
	FRotator PlatformRotationVelocity = FRotator(0.f, 0.f, 0.f);
};
