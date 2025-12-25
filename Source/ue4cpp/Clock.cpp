// Fill out your copyright notice in the Description page of Project Settings.


#include "Clock.h"
//#include "ToolContextInterfaces.h"
#include "Kismet/GameplayStatics.h"
#include "TimeOfDayHandler.h"

// Sets default values
AClock::AClock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->RootSceneComponent = CreateDefaultSubobject<USceneComponent>("RootSceneComponent");
	ClockFace = CreateDefaultSubobject<UStaticMeshComponent>("ClockFace");
	HourHand = CreateDefaultSubobject<UStaticMeshComponent>("HourHand");
	MinuteHand = CreateDefaultSubobject<UStaticMeshComponent>("MinuteHand");
	HourHandle = CreateDefaultSubobject<USceneComponent>("HourHandle");
	MinuteHandle = CreateDefaultSubobject<USceneComponent>("MinuteHandle");
	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'")).Object;
	
	if (MeshAsset)
	{
		ClockFace->SetStaticMesh(MeshAsset);
		HourHand->SetStaticMesh(MeshAsset);
		MinuteHand->SetStaticMesh(MeshAsset);
	}
	
	this->RootComponent = this->RootSceneComponent;
	HourHand->AttachToComponent(HourHandle, FAttachmentTransformRules::KeepRelativeTransform);
	MinuteHand->AttachToComponent(MinuteHandle, FAttachmentTransformRules::KeepRelativeTransform);
	HourHandle->AttachToComponent(RootSceneComponent, FAttachmentTransformRules::KeepRelativeTransform);
	MinuteHandle->AttachToComponent(RootSceneComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ClockFace->AttachToComponent(RootSceneComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ClockFace->SetRelativeTransform(FTransform(FRotator(90, 0,0),
		FVector(10, 0, 0),
		FVector(2, 2, 0.1)));
	HourHand->SetRelativeTransform(FTransform(FRotator(0, 0,0),
		FVector(0, 0, 25),
		FVector(0.1, 0.1, 0.5)));
	MinuteHand->SetRelativeTransform(FTransform(FRotator(0, 0,0),
		FVector(0, 0, 50),
		FVector(0.1, 0.1, 1)));
}

void AClock::TimeChanged(int32 Hours, int32 Minutes)
{
	FString Message = FString::Printf(TEXT("Hour: %d, Minute: %d"), Hours, Minutes);
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, Message);
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
	HourHandle->SetRelativeRotation(FRotator(0, 0,360 / 12 * Hours));
	MinuteHandle->SetRelativeRotation(FRotator(0, 0,360 / 60 * Minutes));
}

// Called when the game starts or when spawned
void AClock::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> TimeOfDayHandlers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATimeOfDayHandler::StaticClass(), TimeOfDayHandlers);
	
	if (TimeOfDayHandlers.Num() > 0)
	{
		auto TimeOfDayHandler = Cast<ATimeOfDayHandler>(TimeOfDayHandlers[0]);
		MyDelegateHandle = TimeOfDayHandler->OnTimeChanged.AddUObject(this, &AClock::TimeChanged);
	}
}

// Called every frame
void AClock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

