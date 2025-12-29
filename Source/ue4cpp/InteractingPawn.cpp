// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractingPawn.h"

#include "Interactable.h"
#include "Kismet/GameplayStatics.h"

void AInteractingPawn::TryInteract()
{
	auto MyController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	if (MyController)
	{
		auto MyCameraManager = MyController->PlayerCameraManager;
		auto StartLocation = MyCameraManager->GetCameraLocation();
		auto EndLocation = StartLocation + MyCameraManager->GetActorForwardVector() * 100;
		FCollisionQueryParams Params;
		FHitResult HitResult;
		GetWorld()->SweepSingleByObjectType(HitResult, StartLocation, EndLocation, FQuat::Identity,
		                                    FCollisionObjectQueryParams(FCollisionObjectQueryParams::AllObjects),
		                                    FCollisionShape::MakeSphere(25),
		                                    FCollisionQueryParams(FName("Interaction"), false, this));

		if (HitResult.Actor != nullptr)
		{
			auto Class = HitResult.Actor->GetClass();

			if (Class->ImplementsInterface(UInteractable::StaticClass()))
			{
				if (IInteractable::Execute_CanInteract(HitResult.Actor.Get()))
				{
					IInteractable::Execute_CanInteract(HitResult.Actor.Get());
					IInteractable::Execute_PerformInteract(HitResult.Actor.Get());
				}
			}
		}
	}
}

void AInteractingPawn::SetupPlayerInputComponent(UInputComponent* InInputComponent)
{
	Super::SetupPlayerInputComponent(InInputComponent);
	InInputComponent->BindAction("Interact", IE_Released, this, &AInteractingPawn::TryInteract);
}
