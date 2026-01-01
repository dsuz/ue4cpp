// Fill out your copyright notice in the Description page of Project Settings.


#include "PostEditChagePropertyActor.h"

APostEditChagePropertyActor::APostEditChagePropertyActor()
{
	auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'")).Object;
	auto SMC = this->GetStaticMeshComponent();
	
	if (Mesh && SMC)
	{
		SMC->SetStaticMesh(Mesh);
		SMC->SetGenerateOverlapEvents(true);
		SMC->SetMobility(EComponentMobility::Movable);
	}
}

void APostEditChagePropertyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.Property != nullptr)
	{
		const FName PropertyName = PropertyChangedEvent.Property->GetFName();
		UE_LOG(LogTemp, Log, TEXT("Changed property: %s"), *PropertyName.ToString());
		
		if (PropertyName == GET_MEMBER_NAME_CHECKED(APostEditChagePropertyActor, ShowStaticMesh))
		{
			auto SMC = this->GetStaticMeshComponent();
			
			if (SMC)
				SMC->SetVisibility(ShowStaticMesh);
		}
	}
	
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
