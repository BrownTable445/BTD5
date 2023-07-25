// Fill out your copyright notice in the Description page of Project Settings.


#include "UpgradeSpecificWidget.h"

void UUpgradeSpecificWidget::NativeConstruct()
{
	//Root = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), FName("Canvas"));
	Button1 = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), FName("Button1"));
	TextBlock1 = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), FName("TextBlock1"));
	TextBlock1->Text = FText::FromString(Description);
}
