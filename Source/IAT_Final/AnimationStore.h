// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"
#include "FourSprite.h"
#include "PaperFlipbook.h"
#include "AnimationStore.generated.h"


UENUM(BluePrintType)
namespace ESpriteFacing
{
	enum Type
	{
		Forward,
		Left,
		Right,
		Backward,
	};
}

/**
 * 
 */
UCLASS(BlueprintType)
class IAT_FINAL_API UAnimationStore : public UDataAsset
{
	GENERATED_UCLASS_BODY()
public:
	UPROPERTY(EditAnywhere, Category = Animations)
		TArray<FFourSprite> Sprites;

	UFUNCTION(BlueprintCallable, Category = AnimationStoreFunctions)
		UPaperFlipbook* GetFlipbook(FText AnimationName, ESpriteFacing::Type Facing)
	{
		int index = 0;
		while (index < Sprites.Num())
		{
			if (Sprites[index].Name.EqualTo(AnimationName))
			{
				break;
			}
			else
			{
				index++;
			}
		}
		index %= Sprites.Num();
		switch (Facing)
		{
		case ESpriteFacing::Forward:
			return Sprites[index].forward;
			break;
		case ESpriteFacing::Left:
			return Sprites[index].left;
			break;
		case ESpriteFacing::Right:
			return Sprites[index].left;
			break;
		case ESpriteFacing::Backward:
			return Sprites[index].back;
			break;
		default:
			return Sprites[index].forward;
			break;
		}
	};
};