// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BloonSpawnRow.h"
#include "Bloon.h"
#include "Defender.h"
#include "Shooter.h"
#include "PlayerControllerReal.h"
#include "ValidSpawnLocationChecker.h"
#include "MyPawn.h"
#include "MySpectatorPawn.h"
#include "BTDGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BTD_API ABTDGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaTime) override;
	ABTDGameModeBase();
	UPROPERTY()
		TArray<UDataTable*> LevelStages;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Level = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int HP = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Money = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool Playing = false; //for now it is true, only when we hit the play button it will be true
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ADefender* Clicked = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<ADefender*> Defenders;
	UPROPERTY()
		TArray<ABloon*> Bloons;
	UPROPERTY()
		UMaterialInterface* DefaultMaterial;
	UPROPERTY()
		UMaterialInterface* EmissiveMaterial;
	UFUNCTION()
		void SpawnBloon(TSubclassOf<ABloon> Bloon);
	UFUNCTION()
		bool isValidSpawnLocation(FVector Location, float Radius);
	UFUNCTION(BlueprintCallable)
		void Play();
	UFUNCTION(BlueprintCallable)
		FVector ConvertViewportPositionToGameCoordinates(UPARAM(ref) FVector& ViewportPosition);
	UFUNCTION()
		AValidSpawnLocationChecker* SpawnChecker(FVector& Location, float Radius);
private:
	const float RATE_OF_CHANGE = 12 / 3.767; //camera location is 43.4322, -8.04, 46.1894
};
