// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Wearable.h"
#include "GameFramework/Actor.h"
#include "Boots.generated.h"

UCLASS()
class UE4CPP_API ABoots : public AActor, public IWearable
{
public:
	virtual bool CanEquip_Implementation(APawn* Wearer) override;
	virtual int32 GetStrengthRequirement_Implementation() override;
	virtual void OnEquip_Implementation(APawn* Wearer) override;

private:
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ABoots();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
