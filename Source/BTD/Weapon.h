// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/SkeletalMesh.h"
#include "Weapon.generated.h"

UCLASS(Abstract, Blueprintable)
class BTD_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int PhysicalDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MagicDamage;
	UPROPERTY()
		USceneComponent* SceneComponent;
	UPROPERTY()
		USkeletalMeshComponent* SkeletalMeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
