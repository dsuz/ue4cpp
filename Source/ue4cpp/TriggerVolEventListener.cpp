// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerVolEventListener.h"

// Sets default values
ATriggerVolEventListener::ATriggerVolEventListener()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	this->RootComponent = this->PointLight;
}

void ATriggerVolEventListener::OnTriggerEvent() const
{
	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Green, TEXT("OnTriggerEvent"));
	auto CurrentColor = this->PointLight->GetLightColor();
	this->PointLight->SetLightColor(CurrentColor != FLinearColor::Yellow ? FLinearColor::Yellow : FLinearColor::Blue);
}

void ATriggerVolEventListener::OneParam(FString Message) const
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Message);
}

// Called when the game starts or when spawned
void ATriggerVolEventListener::BeginPlay()
{
	Super::BeginPlay();

	if (this->TriggerEventSource)
	{
		this->TriggerEventSource->OnPlayerEntered.AddUObject(this, &ATriggerVolEventListener::OnTriggerEvent);
		this->TriggerEventSource->OnOneParam.AddUObject(this, &ATriggerVolEventListener::OneParam);
	}
}

// Called every frame
void ATriggerVolEventListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
