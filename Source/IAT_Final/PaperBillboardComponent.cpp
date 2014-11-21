// Fill out your copyright notice in the Description page of Project Settings.

#include "IAT_Final.h"
#include "PaperBillboardComponent.h"

UPaperBillboardComponent::UPaperBillboardComponent(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	bTickInEditor = true;
}


void UPaperBillboardComponent::TickFacing(float DeltaTime)
{
	if (GEngine)
	{
		// Get Camera rotation
		if (GEngine->GetFirstLocalPlayerController(GetWorld()))
		{
			FRotator playerRotation;
			playerRotation = GEngine->GetFirstLocalPlayerController(GetWorld())->PlayerCameraManager->GetCameraRotation();

			playerRotation.Pitch = 0;
			playerRotation.Yaw += 90;

			// Set sprite rotation
			SetWorldRotation(playerRotation);
		}
	}
}

void UPaperBillboardComponent::TickComponent(float DeltaTime, enum ELevelTick, FActorComponentTickFunction* ThisTickFunction)
{
	TickFlipbook(DeltaTime);
	CalculateCurrentFrame();

	TickFacing(DeltaTime);
}