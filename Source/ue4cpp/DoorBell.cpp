// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorBell.h"
#include "Openable.h"

// Sets default values
ADoorBell::ADoorBell()
{
	this->HasBeenPushed = false;
	auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object;
	auto SM = this->FindComponentByClass<UStaticMeshComponent>();
	
	if (SM && Mesh)
	{
		SM->SetStaticMesh(Mesh);
		SM->SetGenerateOverlapEvents(true);
	}
	
	SM->SetMobility(EComponentMobility::Movable);
	SM->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
	SetActorEnableCollision(true);
	DoorToOpen = nullptr;
}

bool ADoorBell::CanInteract_Implementation()
{
	return !(this->HasBeenPushed);
}

void ADoorBell::PerformInteract_Implementation()
{
	HasBeenPushed = true;
	
	if (this->DoorToOpen->GetClass()->ImplementsInterface(UOpenable::StaticClass()))	// IOpenable じゃないの？
	{
		IOpenable::Execute_Open(DoorToOpen);	// Open じゃないの？		
	}
}

// Called when the game starts or when spawned
void ADoorBell::BeginPlay()
{
	Super::BeginPlay();
	
}