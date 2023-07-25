// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/SkeletalMesh.h"
#include "Components/SphereComponent.h"
#include "BloonTile.generated.h"

UCLASS()
class BTD_API ABloonTile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABloonTile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY()
		USkeletalMeshComponent* SkeletalMeshComponent; //probably dont need to set skeletalmeshcomponent generateoverlap events to false because false is by default?
	UPROPERTY()
		USceneComponent* SceneComponent;
	UPROPERTY()
		USphereComponent* SphereComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
