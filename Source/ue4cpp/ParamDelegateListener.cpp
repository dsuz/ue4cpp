// Fill out your copyright notice in the Description page of Project Settings.


#include "ParamDelegateListener.h"

// Sets default values
AParamDelegateListener::AParamDelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
	this->RootComponent = this->PointLight;
}

void AParamDelegateListener::SetLightColor(FLinearColor LightColor, bool EnableLight)
{
	this->PointLight->SetVisibility(EnableLight);

	if (EnableLight)
	{
		this->PointLight->SetLightColor(this->Colors[this->ColorIndex]);
		this->ColorIndex = (this->ColorIndex + 1) % this->Colors.Num();
	}
}

// Called when the game starts or when spawned
void AParamDelegateListener::BeginPlay()
{
	Super::BeginPlay();
	this->MyGameMode = this->GetWorld()->GetAuthGameMode<AMyGameModeBase>();

	if (this->MyGameMode)
	{
		//this->MyGameMode->MyParamDelegate.BindUObject(this, &AParamDelegateListener::SetLightColor);
		this->MyGameMode->MyParamDelegate.BindUObject(this, &AParamDelegateListener::SetLightColor, false);
	}

	// setup colors
	this->Colors = {
		FColor::Blue,
		FColor::Cyan,
		FColor::Emerald,
		FColor::Magenta,
		FColor::Green,
		FColor::Purple,
		FColor::Red
	};
}

// Called every frame
void AParamDelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

