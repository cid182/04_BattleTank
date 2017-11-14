// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
//#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	auto ThisAITank = GetAIControlledTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Unable to find PLAYER tank!"));
	}
	else if (!ThisAITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("ThisAIControlledTank IS NOT possessing a tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("The AI %s is detecting %s"), *(ThisAITank->GetName()), *(PlayerTank->GetName()));
	}
}


ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	return Cast<ATank>(PlayerPawn);
}
