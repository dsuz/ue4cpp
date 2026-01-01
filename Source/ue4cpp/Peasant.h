// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Peasant.generated.h"

/**
 * 
 */
UCLASS()
class UE4CPP_API APeasant : public AStaticMeshActor
{
	GENERATED_BODY()
	APeasant();
	UFUNCTION(BlueprintCallable, Category = "Peasant")
	void Flee(AKing* DeadKing);
};
