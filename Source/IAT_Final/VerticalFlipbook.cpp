// Fill out your copyright notice in the Description page of Project Settings.

#include "IAT_Final.h"
#include "PaperFlipbookComponent.h"
#include "VerticalFlipbook.h"


AVerticalFlipbook::AVerticalFlipbook(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	//bTickInEditor = true;
	PrimaryActorTick.bCanEverTick = true;

	Scene = PCIP.CreateDefaultSubobject<USceneComponent>(this, TEXT("Scene"));
	RootComponent = Scene;

	Sprite = PCIP.CreateDefaultSubobject<UPaperFlipbookComponent>(this, TEXT("Sprite"));
	Sprite->AttachTo(RootComponent);
	
}

void AVerticalFlipbook::Tick(float DeltaSeconds)
{
	if (GEngine)
	{
		// Get Camera rotation
		FRotator playerRotation = GEngine->GetFirstLocalPlayerController(GetWorld())->PlayerCameraManager->GetCameraRotation();
		FRotator* newRot = new FRotator(playerRotation);

		// Modify rotation
		newRot->Pitch = 0;
		newRot->Yaw +=  90;

		// Set sprite rotation
		Sprite->SetWorldRotation(*newRot);
		
	}
}


