// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <list>
#include "ColoredTexture.h"
#include "EnuName.h"
#include "MyObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class UE4CPP_API UMyObject : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Stats)
	float Armor;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Stats)
	float MaxHp;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Stats)
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit)
	TSubclassOf<UObject> UClassOfPlayer;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(MetaClass="GameMode"), Category = Unit)
	FStringClassReference  UClassGameMode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit)
	FColoredTexture Texture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
	TEnumAsByte<Status> Status;
};
