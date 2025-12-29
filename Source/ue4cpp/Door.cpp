// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
	auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object;
	auto SM = this->GetStaticMeshComponent();
	
	if (SM && Mesh)
	{
		SM->SetStaticMesh(Mesh);
		SM->SetGenerateOverlapEvents(true);
	}
	
	SM->SetMobility(EComponentMobility::Movable);
	SM->SetWorldScale3D(FVector(0.3, 2, 3));
	
	SetActorEnableCollision(true);
}

bool ADoor::CanInteract_Implementation()
{
	return true;
}

void ADoor::PerformInteract_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "The door won't open.");
}

void ADoor::Open_Implementation()
{
	this->AddActorLocalOffset(FVector(0, 0, 200));
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}
