// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateActorComponent.h"

// Sets default values for this component's properties
URotateActorComponent::URotateActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotateActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void URotateActorComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (this->Type == ERotationType::Quat)
	{
		FQuat Quat = FQuat(FVector(0, 1, 0), GetWorld()->TimeSeconds * PI / 4.f);
		GetOwner()->SetActorRotation(Quat);
	}
	else if (this->Type == ERotationType::Rotation)
	{
		FRotator Rotation = FRotator::ZeroRotator;
		Rotation.Yaw += GetWorld()->TimeSeconds * 10;
		GetOwner()->SetActorRotation(Rotation);
	}
}
