// Fill out your copyright notice in the Description page of Project Settings.


#include "OnConstructionActor.h"

AOnConstructionActor::AOnConstructionActor()
{
	auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'")).Object;
	auto SMC = GetStaticMeshComponent();
	
	if (Mesh && SMC)
	{
		SMC->SetStaticMesh(Mesh);
	}
	
	//ShowStaticMesh = true;
}

void AOnConstructionActor::OnConstruction(const FTransform& Transform)
{
	UE_LOG(LogTemp, Log, TEXT("AOnConstructionActor::OnConstruction"));
	GetStaticMeshComponent()->SetVisibility(ShowStaticMesh);
}
