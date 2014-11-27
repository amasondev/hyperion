// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperFlipbook.h"
#include "FourSprite.generated.h"

/**
 * 
 */
USTRUCT()
struct FFourSprite
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, Category = Sprites)
		FText Name;
	UPROPERTY(EditAnywhere, Category = Sprites)
		UPaperFlipbook *forward;
	UPROPERTY(EditAnywhere, Category = Sprites)
		UPaperFlipbook *left;
	UPROPERTY(EditAnywhere, Category = Sprites)
		UPaperFlipbook *back;
};