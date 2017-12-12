// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
//#include "Tank.h"






void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController Begin Play"));

	auto MyControlledTank = GetControlledTank();

	if (!MyControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerControlller IS NOT possessing a tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerControlller is possessing %s"), *(MyControlledTank->GetName()));
	}
}


// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	
	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerControlller IS NOT possessing a tank! Cannot AimTowardsCrosshair."));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerControlller is calling AimTowardsCrosshair"));
	
	// Get world location if linetrace through crosshair hits landscape
	// If it hits landscape...
		// Tell controlled Tank to aim at this point

	return;
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
