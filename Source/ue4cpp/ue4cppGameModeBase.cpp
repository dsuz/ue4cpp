// Copyright Epic Games, Inc. All Rights Reserved.


#include "ue4cppGameModeBase.h"
//#include "MyFirstActor.h"

void Aue4cppGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Spawning Actor..."));
	FTransform SpawnTransform;
	SpawnedActor = GetWorld()->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(), SpawnTransform);
	SpawnedActor->SetLifeSpan(10.0f);

	AnotherSpawnedActor = GetWorld()->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(), SpawnTransform);
	AnotherSpawnedActor->SetLifeSpan(15.0f);
	//FTimerHandle Timer;
	//GetWorldTimerManager().SetTimer(Timer, this, &Aue4cppGameModeBase::DestroyActor, 10.0f);
}

void Aue4cppGameModeBase::DestroyActor()
{
	if (SpawnedActor)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Destroying Actor..."));
		SpawnedActor->Destroy();
	}
}
