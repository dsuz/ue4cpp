// Fill out your copyright notice in the Description page of Project Settings.


#include "AntiGravityVolume.h"

#include "GravityObject.h"

// Sets default values
AAntiGravityVolume::AAntiGravityVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(FName("CollisionComponent"));
	CollisionComponent->SetBoxExtent(FVector(200.0f, 200.0f, 400.0f));
	RootComponent = CollisionComponent;
}

// Called when the game starts or when spawned
void AAntiGravityVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAntiGravityVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAntiGravityVolume::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	IGravityObject* GravityObject = Cast<IGravityObject>(OtherActor);
	
	if (GravityObject)
	{
		GravityObject->DisableGravity();
	}
}

void AAntiGravityVolume::NotifyActorEndOverlap(AActor* OtherActor)
{
	Super::NotifyActorEndOverlap(OtherActor);
	IGravityObject* GravityObject = Cast<IGravityObject>(OtherActor);
	
	if (GravityObject)
	{
		GravityObject->EnableGravity();
	}
}

