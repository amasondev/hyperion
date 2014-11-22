// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"
#include "FourSprite.h"
#include "AnimationStore.generated.h"

/**
 * 
 */
UCLASS()
class IAT_FINAL_API UAnimationStore : public UDataAsset
{
	GENERATED_UCLASS_BODY()

private:
	UPROPERTY(EditAnywhere, Category = Animations)
		TArray<FFourSprite> Sprites;
	
};


