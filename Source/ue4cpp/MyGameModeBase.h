// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyInterface.h"
#include "InventoryCharacter.h"
#include "MyGameModeBase.generated.h"

/**
 * 1
 */
DECLARE_DELEGATE(FStandardDelegateSignature)
DECLARE_DELEGATE_OneParam(FParamDelegateSignature, FLinearColor)
DECLARE_MULTICAST_DELEGATE(FMulticastDelegateSignature)

UCLASS()
class UE4CPP_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	AMyGameModeBase();
	FStandardDelegateSignature MyStandardDelegate;
	FParamDelegateSignature MyParamDelegate;
	FMulticastDelegateSignature MyMulticastDelegate;
	UFUNCTION(BlueprintCallable, Category = "UI")
	void ButtonClicked();
	
private:
	TArray<IMyInterface*> MyInterfaceInstances;
};
