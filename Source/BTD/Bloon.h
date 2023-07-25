// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "BloonRight.h"
#include "BloonLeft.h"
#include "BloonBackward.h"
#include "BloonForward.h"
#include "Projectile.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/SkeletalMesh.h"
#include "Bloon.generated.h"

UCLASS(Abstract, Blueprintable)
class BTD_API ABloon : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABloon();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBoxComponent* Box;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMeshComponent* SkeletalMeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int HP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Armor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MagicResist;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Size;
	UPROPERTY()
		bool Invaded = false; //did the bloon get pass all the defenders?

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
		void GetDamageTaken(ABloon* Bloonn, AWeapon* weapon);
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* SceneComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UProjectileMovementComponent* ProjectileMovement;
	UFUNCTION(BlueprintCallable)
		void CheckMove();
	UFUNCTION(BlueprintCallable)
		void HandleProjectiles();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
