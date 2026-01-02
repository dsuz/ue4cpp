// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"

#include "EngineUtils.h"
#include "SingleInterfaceActor.h"
#include "ue4cpp.h"

void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Warning Log"));
	UE_LOG(LogCh11, Display, TEXT("Display Log"));
	UE_LOG(LogCh11, Log, TEXT("Log"));
	UE_LOG(LogCh11, Warning, TEXT("Warning Log"));
	UE_LOG(LogCh11, Error, TEXT("Error Log"));
	
	CreateLog(LoggerName);
	//FMessageLog Logger(LoggerName);

	auto Logger = new FMessageLog(LoggerName);
	Logger->Warning(FTEXT("A warning message from gamemode via FMessageLog."));
	delete Logger;
	
	//GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;

	/*
	FTransform SpawnTransform;
	ASingleInterfaceActor* SpawnedActor = GetWorld()->SpawnActor<ASingleInterfaceActor>(ASingleInterfaceActor::StaticClass(), SpawnTransform);
	UClass* SpawnedActorClass = SpawnedActor->GetClass();
	
	if (SpawnedActorClass->ImplementsInterface(UMyInterface::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(01, 10, FColor::Green, TEXT("Spawned Actor implements UMyInterface"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(01, 10, FColor::Red, TEXT("Spawned Actor does not implement UMyInterface"));
	}
	
	FString Message = SpawnedActor->GetTestName();
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, Message);
	
	for (TActorIterator<AActor> It(GetWorld(), AActor::StaticClass()); It; ++It)	// ここの for 文の意味がわからない
	{
		auto Actor = *It;
		auto MyInterfaceInstance = Cast<IMyInterface>(Actor);
		
		if (MyInterfaceInstance)
			MyInterfaceInstances.Add(MyInterfaceInstance);
	}
	
	Message = FString::Printf(TEXT("Actors implements IMyInterface: %d"), MyInterfaceInstances.Num());
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, Message);
	*/
}

AMyGameModeBase::AMyGameModeBase()
{
	this->DefaultPawnClass = AInventoryCharacter::StaticClass();
}

void AMyGameModeBase::ButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("ButtonClicked"));
}
