// Fill out your copyright notice in the Description page of Project Settings.


#include "Barracks.h"
#include "Particles/ParticleSystemComponent.h"
#include "BarracksUnit.h"

// Sets default values
ABarracks::ABarracks()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->BuildingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BuildingMesh"));
	this->SpawnPoint = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SpawnPoint"));
	SpawnInterval = 10.0f;
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(
		TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object;

	if (MeshAsset)
	{
		this->BuildingMesh->SetStaticMesh(MeshAsset);
	}

	auto ParticleSystem = ConstructorHelpers::FObjectFinder<UParticleSystem>(
		TEXT("ParticleSystem'/Engine/Tutorial/SubEditors/TutorialAssets/TutorialParticleSystem.TutorialParticleSystem'")).Object;
	
	if(ParticleSystem)
	{
		this->SpawnPoint->SetTemplate(ParticleSystem);
	}

	this->SpawnPoint->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	UnitToSpawn = ABarracksUnit::StaticClass();
}

// Called when the game starts or when spawned
void ABarracks::BeginPlay()
{
	Super::BeginPlay();
	this->RootComponent = this->BuildingMesh;
	this->SpawnPoint->AttachTo(this->RootComponent);
	this->SpawnPoint->SetRelativeLocation(FVector(150.0f, 0.0f, 0.0f));
	this->GetWorld()->GetTimerManager().SetTimer(
		SpawnTimerHandle, this, &ABarracks::SpawnUnit, SpawnInterval, true);
}

// Called every frame
void ABarracks::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABarracks::SpawnUnit()
{
	FVector SpawnLocation = this->SpawnPoint->GetComponentLocation();
	this->GetWorld()->SpawnActor(UnitToSpawn, &SpawnLocation);
	GEngine->AddOnScreenDebugMessage(
		-1, 5.f, FColor::Green, TEXT("Unit Spawned"));
}

void ABarracks::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
}

