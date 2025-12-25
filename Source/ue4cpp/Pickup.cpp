// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "GameFramework/RotatingMovementComponent.h"

// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->MyMesh = CreateDefaultSubobject<UStaticMeshComponent>("MyMesh");
	this->RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>("RotatingMovement");
	this->RootComponent = this->MyMesh;
	auto AssetReference = TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'");
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(AssetReference).Object;
	
	if (MeshAsset)
	{
		MyMesh->SetStaticMesh(MeshAsset);
	}
	
	MyMesh->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	this->RotatingMovement->RotationRate = FRotator(10.0f, 0.0f, 10.0f);
}

void APickup::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	OnPickedUp.ExecuteIfBound();
}

void APickup::BeginPlay()
{
	Super::BeginPlay();
}

void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// // Called when the game starts or when spawned
// void APickup::BeginPlay()
// {
//
// }
//
// // Called every frame
// void APickup::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);
//
// }

