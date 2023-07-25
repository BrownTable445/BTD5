// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Kismet/GameplayStatics.h>
#include "Shooter.h"
#include "PlayerControllerReal.h"
#include <Blueprint/WidgetLayoutLibrary.h>
#include "BTDGameModeBase.h"
#include "ShooterWidget.generated.h"

/**
 * 
 */
UCLASS()
class BTD_API UShooterWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		void SpawnDefender();
		virtual void NativeConstruct() override;
	UPROPERTY()
		ABTDGameModeBase* BTDGameModeBase;
};
