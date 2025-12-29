// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Killable.h"
#include "Undead.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UUndead : public UKillable
{
	GENERATED_BODY()
};

/**
 * 
 */
class UE4CPP_API IUndead : public IKillable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual bool IsDead() override;
	virtual void Die() override;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category=Undead)
	void Turn();
	UFUNCTION(Category=Undead)
	virtual void Banish();
};
