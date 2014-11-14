// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PaperFlipbookComponent.h"
#include "VerticalFlipbook.generated.h"

/**
 * 
 */

UCLASS()
class IAT_FINAL_API AVerticalFlipbook : public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY()
	TSubobjectPtr<class USceneComponent> Scene;

	UPROPERTY(Category = Sprite, VisibleAnywhere)
	TSubobjectPtr<class UPaperFlipbookComponent> Sprite;
	
	//OVERRIDES
	virtual void Tick( float DeltaSeconds ) override;

public:
	bool bTickInEditor;
};
