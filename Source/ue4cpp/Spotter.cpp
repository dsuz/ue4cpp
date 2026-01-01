// Fill out your copyright notice in the Description page of Project Settings.


#include "Spotter.h"

#include "DrawDebugHelpers.h"
//#include "AITypes.h"

ASpotter::ASpotter()
{
	this->PrimaryActorTick.bCanEverTick = true;
	auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'")).Object;
	auto SM = GetStaticMeshComponent();
	
	if (Mesh && SM)
	{
		SM->SetStaticMesh(Mesh);
		SM->SetGenerateOverlapEvents(true);
		SM->SetMobility(EComponentMobility::Movable);
		SM->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
	}
}

void ASpotter::Tick(float DeltaSeconds)
{
	//Super::Tick(DeltaSeconds);
	auto EndLocatin = GetActorLocation() + ActorToWorld().TransformVector(FVector(0.0f, 0.0f, -200.0f));
	FHitResult Hit;
	GetWorld()->SweepSingleByChannel(Hit, GetActorLocation(), EndLocatin, FQuat::Identity,
		ECC_Camera, FCollisionShape::MakeSphere(25), FCollisionQueryParams("Spot", true, this));
	auto SpottedPlayer = Cast<APawn>(Hit.GetActor());
	
	if (SpottedPlayer)
	{
		OnPlayerSpotted(SpottedPlayer);
	}
	
	DrawDebugLine(GetWorld(), GetActorLocation(), EndLocatin, FColor::Red);
}
