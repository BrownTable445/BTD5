// Fill out your copyright notice in the Description page of Project Settings.


#include "UpgradeWidget.h"

void UUpgradeWidget::NativeConstruct()
{
	BTDGameModeBase = Cast<ABTDGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	RootWidget = Cast<UPanelWidget>(GetRootWidget());
}

void UUpgradeWidget::UpdateUpgradePaths(UUpgradeSpecificWidget* UpgradeSpecificWidget)
{
	if (BTDGameModeBase->Clicked) {
		UpgradePath1->TextBlock1->SetText(FText::FromString(""));
		UpgradePath2->TextBlock1->SetText(FText::FromString(""));
		UpgradePath3->TextBlock1->SetText(FText::FromString(""));
		for (auto i : BTDGameModeBase->Clicked->UpgradePaths) {
			UpgradePath1->TextBlock1->SetText(FText::FromString(i->Upgrades[0]->Name + "\n" + i->Upgrades[0]->Description + "\n" + FString::FromInt(i->Upgrades[0]->Cost)));
		}
	}
}
