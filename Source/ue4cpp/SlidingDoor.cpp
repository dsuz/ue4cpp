// Fill out your copyright notice in the Description page of Project Settings.


#include "SlidingDoor.h"

ASlidingDoor::ASlidingDoor()
{
	auto SM = GetStaticMeshComponent();
	auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object;
	
	if (SM && Mesh)
	{
		SM->SetStaticMesh(Mesh);
		SM->SetGenerateOverlapEvents(true);
		SM->SetMobility(EComponentMobility::Movable);
		SM->SetWorldScale3D(FVector(0.3f, 2, 3));
		SetActorEnableCollision(true);
	}
	
	this->IsOpen = false;
	this->PrimaryActorTick.bCanEverTick = true;
}

void ASlidingDoor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (IsOpen)
	{
		SetActorLocation(FMath::Lerp(this->GetActorLocation(), TargetLocation, DeltaSeconds));
	}
}

void ASlidingDoor::BeginPlay()
{
	Super::BeginPlay();
}

void ASlidingDoor::Open()
{
	TargetLocation = ActorToWorld().TransformPositionNoScale(FVector(0.0f, 0.0f, 200.0f));
	IsOpen = true;
}
