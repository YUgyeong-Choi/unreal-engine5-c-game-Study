// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovingPlatform(DeltaTime);
	RotationPlatform(DeltaTime);
}

void AMovingPlatform::MovingPlatform(float DeltaTime)
{
	DistanceMoved = GetDistanceMoved();

	if (DistanceMoved >= MoveDistance )
	{
		//100까지 가야 하는데 5를 넘겼다면 Overshoot이 5
		float Overshoot = DistanceMoved - MoveDistance;

		// 어느 방향으로 움직이고 있는 지 뽑아낸 것
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();

		//우리가 원래 도달하고 싶었던 정확한 목표 위치
		FVector NewStartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(NewStartLocation);
		StartLocation = NewStartLocation;

		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		FVector NewLocation = GetActorLocation() + (PlatformVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}
}

void AMovingPlatform::RotationPlatform(float DeltaTime)
{
	FRotator NewRotation = GetActorRotation() + FRotator(PlatformRotationVelocity * DeltaTime);
	SetActorRotation(NewRotation);

	// 선생님 코드
	//AddActorLocalRotation(PlatformRatationVelocity * DeltaTime);
}

float AMovingPlatform::GetDistanceMoved()
{
	return FVector::Dist(StartLocation, GetActorLocation());
}