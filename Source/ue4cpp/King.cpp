// Fill out your copyright notice in the Description page of Project Settings.


#include "King.h"

AKing::AKing()
{
	auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'")).Object;
	auto SMC = GetStaticMeshComponent();
	
	if (Mesh && SMC)
	{
		SMC->SetStaticMesh(Mesh);
		SMC->SetMobility(EComponentMobility::Movable);
		SMC->SetGenerateOverlapEvents(true);
	}
}

void AKing::Die()
{
	OnKingDeath.Broadcast(this);
}
