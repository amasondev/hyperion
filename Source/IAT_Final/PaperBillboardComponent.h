// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperFlipbookComponent.h"
#include "PaperBillboardComponent.generated.h"

/**
 * 
 */
UCLASS(ShowCategories = (Mobility, ComponentReplication), ClassGroup = Paper2D, meta=(BlueprintSpawnableComponent))
class IAT_FINAL_API UPaperBillboardComponent : public UPaperFlipbookComponent
{
	GENERATED_UCLASS_BODY()

	
public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	void TickFacing(float DeltaTime);
};
