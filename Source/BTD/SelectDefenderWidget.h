// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BTDGameModeBase.h"
#include <Blueprint/WidgetLayoutLibrary.h>
#include "UpgradeWidget.h"
#include "SelectDefenderWidget.generated.h"

/**
 * 
 */
UCLASS()
class BTD_API USelectDefenderWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
	UPROPERTY()
		ABTDGameModeBase* BTDGameModeBase;
	UFUNCTION(BlueprintCallable)
		void OnClicked();
};
