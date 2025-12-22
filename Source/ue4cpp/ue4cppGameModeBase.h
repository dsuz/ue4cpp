// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyObject.h"
#include "MyFirstActor.h"
#include "ue4cppGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UE4CPP_API Aue4cppGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = UClassNames)
	TSubclassOf<UMyObject> UPBlueprintClassOfMyObject;

	void BeginPlay() override;

	UPROPERTY()
	AMyFirstActor* SpawnedActor;

	UPROPERTY()
	AActor* AnotherSpawnedActor;

	UFUNCTION()
	void DestroyActor();
};
