// Fill out your copyright notice in the Description page of Project Settings.


#include "SelectableCube.h"

ASelectableCube::ASelectableCube() : Super()
{
	this->MyMesh->SetNotifyRigidBodyCollision(true);
}

void ASelectableCube::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	//Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	//if (ISelectable::IsSelectable())
	if (this->ISelectable::IsSelectable())
	{
		TrySelect();
	}
}
