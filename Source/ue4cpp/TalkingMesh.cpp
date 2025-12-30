// Fill out your copyright notice in the Description page of Project Settings.


#include "TalkingMesh.h"

ATalkingMesh::ATalkingMesh()
{
	auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object;
	auto SM = this->GetStaticMeshComponent();
	
	if (SM && Mesh)
	{
		SM->SetStaticMesh(Mesh);
		SM->SetGenerateOverlapEvents(true);
		SM->SetMobility(EComponentMobility::Movable);
	}
	
	this->SetActorEnableCollision(true);
}

void ATalkingMesh::StartTalking_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Talking Mesh Start"));
}
