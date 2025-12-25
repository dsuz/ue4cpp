// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeOfDayHandler.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnTimeChangedSignature, int32, int32)

UCLASS()
class UE4CPP_API ATimeOfDayHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimeOfDayHandler();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FOnTimeChangedSignature OnTimeChanged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 TimeScale = 60;
	UPROPERTY()
	int32 Hours;
	UPROPERTY()
	int32 Minutes;
	UPROPERTY()
	float ElapsedSeconds;
};
