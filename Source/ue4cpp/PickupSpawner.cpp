// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupSpawner.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
APickupSpawner::APickupSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->SpawnLocation = CreateDefaultSubobject<USceneComponent>("SpawnLocation");
	this->RootComponent = this->SpawnLocation;
}

void APickupSpawner::PickupCollected()
{
	this->GetWorld()->GetTimerManager().SetTimer(MyTimer, this, &APickupSpawner::SpawnPickup, 10.0f, false);
	CurrentPickup->OnPickedUp.Unbind();
	CurrentPickup->Destroy();
}

void APickupSpawner::SpawnPickup()
{
	auto World = GetWorld();
	
	if (World)
	{
		CurrentPickup = World->SpawnActor<APickup>(APickup::StaticClass(), GetTransform());
		CurrentPickup->OnPickedUp.BindUObject(this, &APickupSpawner::PickupCollected);
	}
}

// Called when the game starts or when spawned
void APickupSpawner::BeginPlay()
{
	Super::BeginPlay();
	SpawnPickup();
}

// Called every frame
void APickupSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

