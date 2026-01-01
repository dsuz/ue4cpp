// Fill out your copyright notice in the Description page of Project Settings.


#include "Peasant.h"

#include "King.h"

APeasant::APeasant()
{
	auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object;
	auto SMC = this->GetStaticMeshComponent();
	
	if (Mesh && SMC)
	{
		SMC->SetStaticMesh(Mesh);
		SMC->SetGenerateOverlapEvents(true);
		SMC->SetMobility(EComponentMobility::Movable);
	}
}

void APeasant::Flee(AKing* DeadKing)
{
	auto Message = FString::Printf(TEXT("%s is dead!"), *DeadKing->GetName());
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, Message);
	auto FleeVector = GetActorLocation() - DeadKing->GetActorLocation();
	FleeVector.Normalize();
	FleeVector *= 500;
	SetActorLocation(this->GetActorLocation() + FleeVector);
}
