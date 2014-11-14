// Fill out your copyright notice in the Description page of Project Settings.

#include "IAT_Final.h"
#include "PaperBillboardComponent.h"
#include "UnrealEd.h"
#include "EditorViewportClient.h"

UPaperBillboardComponent::UPaperBillboardComponent(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	
}


void UPaperBillboardComponent::TickFacing(float DeltaTime)
{
	if (GEngine)
	{
		FRotator playerRotation;
		// Get Camera rotation
		if (!GIsEditor || GEditor->GetPIEViewport())
		{
			playerRotation = GEngine->GetFirstLocalPlayerController(GetWorld())->PlayerCameraManager->GetCameraRotation();
		}
		else {
			//playerRotation = GEditor->LevelViewportClients[2]->GetViewRotation();
			FLevelEditorViewportClient* client = (FLevelEditorViewportClient*)GEditor->GetActiveViewport()->GetClient();
			if (client)
			{
				playerRotation = client->GetViewRotation();
			}
		}

		playerRotation.Pitch = 0;
		playerRotation.Yaw += 90;

		// Set sprite rotation
		SetWorldRotation(playerRotation);
	}
}

void UPaperBillboardComponent::TickComponent(float DeltaTime, enum ELevelTick, FActorComponentTickFunction* ThisTickFunction)
{
	TickFlipbook(DeltaTime);
	CalculateCurrentFrame();

	TickFacing(DeltaTime);
}