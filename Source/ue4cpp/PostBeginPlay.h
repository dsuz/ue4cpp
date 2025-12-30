// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PostBeginPlay.generated.h"

// This class does not need to be modified.
UINTERFACE(meta=(CannotImplementInterfaceInBlueprint))
class UPostBeginPlay : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UE4CPP_API IPostBeginPlay
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category=Test)
	virtual void OnPostBeginPlay();
};
