// Fill out your copyright notice in the Description page of Project Settings.


#include "PostBeginPlay.h"

// Add default functionality here for any IPostBeginPlay functions that are not pure virtual.
void IPostBeginPlay::OnPostBeginPlay()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString(__FUNCTION__));
}
