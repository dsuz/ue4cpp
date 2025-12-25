// Fill out your copyright notice in the Description page of Project Settings.


#include "DelegateListener.h"
#include "MyGameModeBase.h"

// Sets default values
ADelegateListener::ADelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	this->RootComponent = this->PointLight;
	
	this->PointLight->SetLightColor(FLinearColor::Red);
}

// Called when the game starts or when spawned
void ADelegateListener::BeginPlay()
{
	auto LifeSpan = FMath::FRand() * 5.0f + 3.0f;
	this->SetLifeSpan(LifeSpan);
	this->PointLight->SetVisibility(this->EnabledLightByDefault);
	Super::BeginPlay();
	auto* TheWorld = GetWorld();

	if (TheWorld)
	{
		//AGameModeBase* GameMode = TheWorld->GetAuthGameMode<AGameModeBase>();
		//AMyGameModeBase* MyGameMode = Cast<AMyGameModeBase>(GameMode);
		this->MyGameMode = TheWorld->GetAuthGameMode<AMyGameModeBase>();
		
		if (this->MyGameMode)
		{
			//this->MyGameMode->MyStandardDelegate.BindUObject(this, &ADelegateListener::EnableLight);
			this->MyDelegateHandle = this->MyGameMode->MyMulticastDelegate.AddUObject(this, &ADelegateListener::ToggleLight);
		}
	}
}

void ADelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	
	if (this->MyGameMode)
	{
		//this->MyGameMode->MyStandardDelegate.Unbind();
		this->MyGameMode->MyMulticastDelegate.Remove(this->MyDelegateHandle);
		auto Message = FString::Printf(TEXT("EndPlay: %s"), *(this->GetName()));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, Message);
	}
}

// Called every frame
void ADelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void ADelegateListener::EnableLight()
{
	this->PointLight->SetVisibility(true);
}

void ADelegateListener::DisableLight()
{
	this->PointLight->SetVisibility(false);
}

void ADelegateListener::ToggleLight()
{
	this->PointLight->ToggleVisibility();
}

