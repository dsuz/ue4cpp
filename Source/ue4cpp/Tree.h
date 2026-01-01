// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Tree.generated.h"

UENUM(BlueprintType)
enum ETreeType
{
	Tree_Poplar,
	Tree_Spruce,
	Tree_Eucalyptus,
	Tree_RedWood,
};

/**
 * 
 */
UCLASS()
class UE4CPP_API ATree : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	ATree();
	UPROPERTY(BlueprintReadWrite)
	//TEnumAsByte<ETreeType> Type;
	TEnumAsByte<ETreeType> Type;
};
