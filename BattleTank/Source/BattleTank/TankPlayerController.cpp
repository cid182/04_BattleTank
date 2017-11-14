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


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
