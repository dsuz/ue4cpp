// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitingMovementComponent.h"

// Sets default values for this component's properties
UOrbitingMovementComponent::UOrbitingMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	this->RotationSpeed = 25 * 10;
	this->OrbitDistance = 100;
	this->CurrentValue = 0.0f;
	this->RotateToFaceOutwards = true;
}


// Called when the game starts
void UOrbitingMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOrbitingMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	float CurrentValueInRadians = FMath::DegreesToRadians(this->CurrentValue);
	this->SetRelativeLocation(
		FVector(FMath::Cos(CurrentValueInRadians) * this->OrbitDistance,
			FMath::Sin(CurrentValueInRadians) * this->OrbitDistance,
			this->GetRelativeLocation().Z));
	
	if (this->RotateToFaceOutwards)
	{
		FVector LookDirection = this->GetRelativeLocation().GetSafeNormal();
		FRotator LookAtRotation = LookDirection.Rotation();
		this->SetRelativeRotation(LookAtRotation);
	}

	this->CurrentValue = FMath::Fmod(this->CurrentValue + this->RotationSpeed * DeltaTime, 360.0f);
}

