// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AMyActor::BeginPlay()"));
	int i = 39;
	float f = 3.29f;
	FString str = "hello world";
	UE_LOG(LogTemp, Warning, TEXT("%d, %f, %s"), i, f, *str);
	
	auto str2 = FString::Printf(TEXT("int: %d, float:%f, FString:%s"), i, f, *str);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *str2);
	
	TArray<FStringFormatArg> args;
	args.Add(FStringFormatArg(i));
	args.Add(FStringFormatArg(f));
	args.Add(FStringFormatArg(str));
	FString str3 = FString::Format(TEXT("int:{0}, FString:{2}, float:{1}"), args);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *str3);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

