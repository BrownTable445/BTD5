// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloon.h"
#include "Bloon2.generated.h"

/**
 * 
 */
UCLASS()
class BTD_API ABloon2 : public ABloon
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	ABloon2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
