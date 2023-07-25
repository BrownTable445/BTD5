// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BTDGameModeBase.h"
#include "Blueprint/WidgetTree.h"
#include "UpgradeSpecificWidget.h"
#include "UpgradeWidget.generated.h"

/**
 * 
 */
UCLASS()
class BTD_API UUpgradeWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
	UPROPERTY()
		ABTDGameModeBase* BTDGameModeBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UPanelWidget* RootWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UUpgradeSpecificWidget* UpgradePath1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UUpgradeSpecificWidget* UpgradePath2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UUpgradeSpecificWidget* UpgradePath3;
	UFUNCTION()
		void UpdateUpgradePaths(UUpgradeSpecificWidget* UpgradeSpecificWidget);
};
