// Fill out your copyright notice in the Description page of Project Settings.


#include "NonSelectableCube.h"

bool ANonSelectableCube::IsSelectable()
{
	auto Actor = Cast<AActor>(this);
	FString Message = "";
	
	if (Actor)
	{
		Message = FString::Printf(TEXT("%s is NOT selectable"), *Actor->GetName());
	}
	else
	{
		Message = TEXT("Actor not found");
	}
	
	GEngine->AddOnScreenDebugMessage(-20, 3.0f, FColor::Yellow, Message);
	return false;
}

bool ANonSelectableCube::TrySelect()
{
	auto Actor = Cast<AActor>(this);
	FString Message = "";
	
	if (Actor)
	{
		Message = FString::Printf(TEXT("%s refused selection"), *Actor->GetName());
	}
	else
	{
		Message = TEXT("Actor not found");
	}
	
	GEngine->AddOnScreenDebugMessage(-21, 3.0f, FColor::Black, Message);
	return true;
}
