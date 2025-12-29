// Fill out your copyright notice in the Description page of Project Settings.


#include "Selectable.h"

// Add default functionality here for any ISelectable functions that are not pure virtual.
bool ISelectable::IsSelectable()
{
	auto Actor = Cast<AActor>(this);
	FString Message = "";
	
	if (Actor)
	{
		Message = FString::Printf(TEXT("%s is selectable"), *Actor->GetName());
	}
	else
	{
		Message = TEXT("Actor not found");
	}
	
	GEngine->AddOnScreenDebugMessage(-99, 3.0f, FColor::Cyan, Message);
	return true;
}

bool ISelectable::TrySelect()
{
	auto Actor = Cast<AActor>(this);
	FString Message = "";
	
	if (Actor)
	{
		Message = FString::Printf(TEXT("%s accept selection"), *Actor->GetName());
	}
	else
	{
		Message = TEXT("Actor not found");
	}
	
	GEngine->AddOnScreenDebugMessage(-11, 3.0f, FColor::Blue, Message);
	return true;
}

void ISelectable::Deselect()
{
	unimplemented();
}
