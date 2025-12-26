// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerVolume.h"

// Sets default values
AMyTriggerVolume::AMyTriggerVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->TriggerZone = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerZone"));
	this->TriggerZone->SetBoxExtent(FVector(200.f, 200.f, 100.f));
}

void AMyTriggerVolume::OnOverlapEnd_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	auto Message = FString::Printf(TEXT("Overlap End: %s has exited the trigger volume."), *OtherActor->GetName());
	GEngine->AddOnScreenDebugMessage(-2, 5.f, FColor::Magenta, Message);
}

// Called when the game starts or when spawned
void AMyTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
	
	auto* TheWorld = GetWorld();

	if (TheWorld)
	{
		//AGameModeBase* GameMode = TheWorld->GetAuthGameMode<AGameModeBase>();
		//this->MyGameMode = Cast<AMyGameModeBase>(GameMode);
		this->MyGameMode = TheWorld->GetAuthGameMode<AMyGameModeBase>();
	}
}

void AMyTriggerVolume::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	this->TriggerZone->OnComponentBeginOverlap.AddDynamic(this, &AMyTriggerVolume::OnOverlapComponent);
	this->TriggerZone->OnComponentEndOverlap.AddDynamic(this, &AMyTriggerVolume::OnOverlapEnd);
}

// Called every frame
void AMyTriggerVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTriggerVolume::NotifyActorBeginOverlap(AActor* OtherActor)
{
	auto Message = FString::Printf(TEXT("Actor %s has entered the trigger volume."), *OtherActor->GetName());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Message);

	if (MyGameMode)
	{
		MyGameMode->MyStandardDelegate.ExecuteIfBound();
		this->MyGameMode->MyParamDelegate.ExecuteIfBound(FColor::Red);
		this->MyGameMode->MyMulticastDelegate.Broadcast();
	}
	
	OnPlayerEntered.Broadcast();
	OnOneParam.Broadcast(TEXT("One Param"));
}

void AMyTriggerVolume::NotifyActorEndOverlap(AActor* OtherActor)
{
	auto Message = FString::Printf(TEXT("Actor %s has left the trigger volume."), *OtherActor->GetName());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, Message);
}

void AMyTriggerVolume::OnOverlapComponent_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto Message = FString::Printf(TEXT("OnOverlapComponent: %s has entered the trigger volume."), *OtherActor->GetName());
	GEngine->AddOnScreenDebugMessage(-2, 5.f, FColor::Black, Message);
}

