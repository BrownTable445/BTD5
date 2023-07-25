// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Bloon.h"
#include "BTDGameModeBase.h"
#include <Kismet/GameplayStatics.h>
#include "EndPosition.generated.h"

UCLASS()
class BTD_API AEndPosition : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEndPosition();
	UPROPERTY()
		USceneComponent* SceneComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* SphereComponent;
	UPROPERTY()
		ABTDGameModeBase* MyGameMode;
	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
