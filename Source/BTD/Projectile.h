// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.h"
#include "GameFrameWork/ProjectileMovementComponent.h"
#include "Projectile.generated.h"

UCLASS()
class BTD_API AProjectile : public AWeapon
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectile();
	UPROPERTY(EditAnywhere)
		float Range;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ProjectileRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Piercing;
	UPROPERTY()
		UProjectileMovementComponent* ProjectileMovementComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
