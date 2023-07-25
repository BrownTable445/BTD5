// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.h"
#include "UpgradePath.h"
#include "Bloon.h"
#include "Math/Vector.h"
#include "Components/SphereComponent.h"
#include <Kismet/KismetMathLibrary.h>
#include "GameFrameWork/Actor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/SkeletalMesh.h"
#include "Defender.generated.h"

UCLASS(Abstract, Blueprintable)
class BTD_API ADefender : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADefender();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<ABloon*> EncounteredBloons;
	UFUNCTION(BlueprintCallable)
		void UpdateBloonOrder();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USkeletalMeshComponent* SkeletalMeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UUpgradePath*> UpgradePaths;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int PhysicalDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int MagicDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AWeapon*> Weapons;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool WasOverlapped;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector OverlapBeginPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* SceneComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* Sphere;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* SpawnRadius;
	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);
	UFUNCTION()
		void RotateToBloon();
	/*
	* If WasOverlapped == false, then once a bloon overlaps with defender, we get the world location of bloon and then get the velocity of the bloon
	* If velocity is x positive, then we add the length of the box / 2 (or the distance from the center of the box to the edge of the box) to x location of bloon
	* to get the overlap location
	* If the velocity is x negative, then we subtract from the x location
	* If velocity is y positive, we add to the y location
	* If velocity is y negative, we subtract from the y location
	*/
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
