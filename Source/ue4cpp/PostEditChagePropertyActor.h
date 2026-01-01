// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "PostEditChagePropertyActor.generated.h"

/**
 * 
 */
UCLASS()
class UE4CPP_API APostEditChagePropertyActor : public AStaticMeshActor
{
	GENERATED_BODY()
	APostEditChagePropertyActor();
	UPROPERTY(EditAnywhere)
	bool ShowStaticMesh = true;

public:
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};
