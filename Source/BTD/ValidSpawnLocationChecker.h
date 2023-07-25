// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Grass.h"
#include "Defender.h"
#include "ValidSpawnLocationChecker.generated.h"

UCLASS()
class BTD_API AValidSpawnLocationChecker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AValidSpawnLocationChecker();
	float Radius;
	UFUNCTION()
		bool isOverlappingDefenderSpawnRadius();
	UFUNCTION()
		bool OnValidTile();
	UFUNCTION()
		ADefender* GetClickedOnDefender();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* SphereComponent;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY()
		USceneComponent* SceneComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
