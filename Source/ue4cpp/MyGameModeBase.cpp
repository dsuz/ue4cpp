// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"

void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	//GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
}

AMyGameModeBase::AMyGameModeBase()
{
	this->DefaultPawnClass = AInventoryCharacter::StaticClass();
}

void AMyGameModeBase::ButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("ButtonClicked"));
}
