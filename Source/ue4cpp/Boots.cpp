// Fill out your copyright notice in the Description page of Project Settings.


#include "Boots.h"

bool ABoots::CanEquip_Implementation(APawn* Wearer)
{
	return true;
}

int32 ABoots::GetStrengthRequirement_Implementation()
{
	return 0;
}

void ABoots::OnEquip_Implementation(APawn* Wearer)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "Item being worn");
}

// Sets default values
ABoots::ABoots()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoots::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoots::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

