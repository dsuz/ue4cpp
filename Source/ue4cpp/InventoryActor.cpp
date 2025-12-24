// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryActor.h"

AInventoryActor::AInventoryActor() : Super()
{
	PrimaryActorTick.bCanEverTick = true;
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Game/StarterContent/Props/SM_Chair.SM_Chair"));
	
	if (MeshAsset.Succeeded())
	{
		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	}

	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	this->SetActorEnableCollision(true);
}

void AInventoryActor::PickUp()
{
	this->SetActorTickEnabled(false);
	this->SetActorHiddenInGame(true);
	this->SetActorEnableCollision(false);
}

void AInventoryActor::PutDown(FTransform TargetLocation)
{
	this->SetActorTickEnabled(true);
	this->SetActorHiddenInGame(false);
	this->SetActorEnableCollision(true);
	this->SetActorLocation(TargetLocation.GetLocation());
}
