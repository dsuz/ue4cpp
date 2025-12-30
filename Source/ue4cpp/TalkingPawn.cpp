// Fill out your copyright notice in the Description page of Project Settings.


#include "TalkingPawn.h"

#include "Talker.h"

ATalkingPawn::ATalkingPawn() : Super()
{
	this->PrimaryActorTick.bCanEverTick = true;
	this->TalkCollider = CreateDefaultSubobject<UBoxComponent>(FName("TalkCollider"));
	this->TalkCollider->SetBoxExtent(FVector(200.0f, 200.0f, 100.0f));
	this->TalkCollider->OnComponentBeginOverlap.AddDynamic(this, &ATalkingPawn::OnTalkOverlap);
	this->TalkCollider->AttachToComponent(this->RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void ATalkingPawn::OnTalkOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                 UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                 const FHitResult& SweepResult)
{
	auto Class = OtherActor->GetClass();
	
	if (Class->ImplementsInterface(UTalker::StaticClass()))
	{
		ITalker::Execute_StartTalking(OtherActor);
	}
}
