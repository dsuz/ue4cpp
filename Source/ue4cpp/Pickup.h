// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "GameFramework/RotatingMovementComponent.h"
#include "Pickup.generated.h"

class URotatingMovementComponent;
DECLARE_DELEGATE(FPickedUpEventSignature);

UCLASS()
class UE4CPP_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();
	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MyMesh;
	UPROPERTY()
	URotatingMovementComponent* RotatingMovement;
	FPickedUpEventSignature OnPickedUp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
