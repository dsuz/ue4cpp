// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryCharacter.h"

// Sets default values
AInventoryCharacter::AInventoryCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyInventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("MyInventory"));
}

void AInventoryCharacter::DropItem()
{
	if (MyInventory->CurrentInventory.Num() == 0)
	{
		return;
	}

	AInventoryActor* Item = MyInventory->CurrentInventory.Last();
	MyInventory->RemoveFromInventory(Item);

	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds(false, ItemOrigin, ItemBounds);
	FTransform PutDownLocation = this->GetTransform()
		+ FTransform(this->RootComponent->GetForwardVector() * ItemBounds.GetMax());
	Item->PutDown(PutDownLocation);
}

void AInventoryCharacter::TakeItem(AInventoryActor* InventoryItem)
{
	InventoryItem->PickUp();
	MyInventory->AddToInventory(InventoryItem);
}

void AInventoryCharacter::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	AInventoryActor* InventoryItem = Cast<AInventoryActor>(Other);

	if (InventoryItem)
	{
		TakeItem(InventoryItem);
	}
}

void AInventoryCharacter::MoveForward(float AxisValue)
{
	this->MovementInput.X = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void AInventoryCharacter::MoveRight(float AxisValue)
{
	this->MovementInput.Y = FMath::Clamp<float>(AxisValue, -1.0f, 1.0f);
}

void AInventoryCharacter::PitchCamera(float AxisValue)
{
	this->CameraInput.X = AxisValue;
}

void AInventoryCharacter::YawCamera(float AxisValue)
{
	this->CameraInput.Y = AxisValue;
}

// Called when the game starts or when spawned
void AInventoryCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AInventoryCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!this->MovementInput.IsZero())
	{
		this->MovementInput *= 100;
		FVector InputVector = FVector::ZeroVector;
		InputVector += this->GetActorForwardVector() * this->MovementInput.X * DeltaTime;
		InputVector += this->GetActorRightVector() * this->MovementInput.Y * DeltaTime;

		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Green,
			FString::Printf(TEXT("x: %f, y: %f"), InputVector.X, InputVector.Y));

		this->AddMovementInput(InputVector);
	}


	if (!this->CameraInput.IsNearlyZero())
	{
		//FRotator NewRotation = this->GetActorRotation();
		//NewRotation.Pitch += this->CameraInput.Y;
		//NewRotation.Yaw += this->CameraInput.X;
		auto* MyPlayerController = Cast<APlayerController>(this->GetController());

		if (MyPlayerController)
		{
			MyPlayerController->AddYawInput(this->CameraInput.X);
			MyPlayerController->AddPitchInput(-this->CameraInput.Y);
		}

		//this->SetActorRotation(NewRotation);
	}
}

// Called to bind functionality to input
void AInventoryCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("DropItem", IE_Pressed, this, &AInventoryCharacter::DropItem);
	PlayerInputComponent->BindAxis("MoveForward", this, &AInventoryCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AInventoryCharacter::MoveRight);
	PlayerInputComponent->BindAxis("CameraPitch", this, &AInventoryCharacter::PitchCamera);
	PlayerInputComponent->BindAxis("CameraYaw", this, &AInventoryCharacter::YawCamera);
}

