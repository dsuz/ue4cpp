// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObject2.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class UE4CPP_API UMyObject2 : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Stats")
	float Armor;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Stats")
	FString Name;
};
