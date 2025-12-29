// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Interactable.h"
#include "Openable.h"
#include "Door.generated.h"

UCLASS()
class UE4CPP_API ADoor : public AStaticMeshActor, public IInteractable, public IOpenable
{
	GENERATED_BODY()
	
public:	
	ADoor();
	virtual bool CanInteract_Implementation() override;
	virtual void PerformInteract_Implementation() override;
	virtual void Open_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
