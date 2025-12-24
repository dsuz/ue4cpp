// Fill out your copyright notice in the Description page of Project Settings.


#include "BarracksUnit.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ABarracksUnit::ABarracksUnit()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->VisualRepresentation = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SpawnPoint"));
	auto ParticleSystem = ConstructorHelpers::FObjectFinder<UParticleSystem>(
		TEXT("ParticleSystem'/Engine/Tutorial/SubEditors/TutorialAssets/TutorialParticleSystem.TutorialParticleSystem'")).Object;

	if (ParticleSystem)
	{
		this->VisualRepresentation->SetTemplate(ParticleSystem);
	}

	this->VisualRepresentation->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
}

// Called when the game starts or when spawned
void ABarracksUnit::BeginPlay()
{
	Super::BeginPlay();
	this->VisualRepresentation->AttachTo(RootComponent);
}

// Called every frame
void ABarracksUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->SetActorLocation(
		this->GetActorLocation() + FVector(10.0f, 0.0f, 0.0f));
}

// Called to bind functionality to input
void ABarracksUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

