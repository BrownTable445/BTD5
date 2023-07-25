// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BloonTile.h"
#include "BloonRight.generated.h"

UCLASS()
class BTD_API ABloonRight : public ABloonTile
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABloonRight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
