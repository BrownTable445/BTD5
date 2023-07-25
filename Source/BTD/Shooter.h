// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Defender.h"
#include "ShooterProjectile.h"
#include "Components/ArrowComponent.h"
#include "Animation/AnimationAsset.h"
#include <Kismet/GameplayStatics.h>
#include "Shooter.generated.h"

UCLASS()
class BTD_API AShooter : public ADefender
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShooter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ProjectileSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ProjectileRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Piercing;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTimerHandle MemberTimerHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UArrowComponent* Arrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AShooterProjectile> ActorClassToBeSpawned;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAnimationAsset* Animation;
	UFUNCTION()
		void ClearInvalidBloons();
	UFUNCTION()
		void ShootProjectile();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
