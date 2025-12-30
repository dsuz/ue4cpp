// Fill out your copyright notice in the Description page of Project Settings.


#include "CppComponent.h"

// Sets default values for this component's properties
UCppComponent::UCppComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UCppComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

int32 UCppComponent::Add(int32 a, int32 b)
{
	return a + b;
}

