// Fill out your copyright notice in the Description page of Project Settings.


#include "HierarchyActor.h"

// Sets default values
AHierarchyActor::AHierarchyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Child1 = CreateDefaultSubobject<USceneComponent>(TEXT("Child1"));
	Box1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box1"));
	Box2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box2"));
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Engine/BasicShapes/Cube.Cube")).Object;
	
	if (MeshAsset)
	{
		Box1->SetStaticMesh(MeshAsset);
		Box2->SetStaticMesh(MeshAsset);
	}

	this->RootComponent = Root;

	Box1->AttachTo(Root);
	Box2->AttachTo(Child1);
	Child1->AttachTo(Root);
	Child1->SetRelativeTransform(FTransform(
		FRotator(0.f, 45.f, 0.f),
		FVector(200.f, 0.f, 0.f),
		FVector(1.f, 1.f, 1.f)));
}

// Called when the game starts or when spawned
void AHierarchyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHierarchyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

