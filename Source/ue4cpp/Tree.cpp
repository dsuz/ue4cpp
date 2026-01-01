// Fill out your copyright notice in the Description page of Project Settings.


#include "Tree.h"

ATree::ATree()
{
	auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'")).Object;
	auto SMC = GetStaticMeshComponent();
	
	if (Mesh && SMC)
	{
		SMC->SetStaticMesh(Mesh);
		SMC->SetGenerateOverlapEvents(true);
		SMC->SetMobility(EComponentMobility::Movable);
	}
}
