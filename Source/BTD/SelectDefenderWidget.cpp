// Fill out your copyright notice in the Description page of Project Settings.


#include "SelectDefenderWidget.h"

void USelectDefenderWidget::NativeConstruct()
{
	BTDGameModeBase = Cast<ABTDGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));//need to somehow get a reference to the upgradewidgetblueprint
}

void USelectDefenderWidget::OnClicked()
{
	FVector WorldLocation, WorldDirection;
	FVector2D Position = UWidgetLayoutLibrary::GetMousePositionOnViewport(GetWorld());
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->DeprojectScreenPositionToWorld(Position.X, Position.Y, WorldLocation, WorldDirection);
	WorldLocation = BTDGameModeBase->ConvertViewportPositionToGameCoordinates(WorldLocation);

	AValidSpawnLocationChecker* Checker = BTDGameModeBase->SpawnChecker(WorldLocation, 2.5);
	ADefender* Defender = Checker->GetClickedOnDefender();
	if (Defender) {
		if (!BTDGameModeBase->Clicked) {
			BTDGameModeBase->Clicked = Defender;
			BTDGameModeBase->Clicked->SkeletalMeshComponent->SetMaterial(0, BTDGameModeBase->EmissiveMaterial);
		}
		else {
			BTDGameModeBase->Clicked->SkeletalMeshComponent->SetMaterial(0, BTDGameModeBase->DefaultMaterial);
			BTDGameModeBase->Clicked = Defender;
			BTDGameModeBase->Clicked->SkeletalMeshComponent->SetMaterial(0, BTDGameModeBase->EmissiveMaterial);
		}
	}
	else if (BTDGameModeBase->Clicked) {
			BTDGameModeBase->Clicked->SkeletalMeshComponent->SetMaterial(0, BTDGameModeBase->DefaultMaterial);
			BTDGameModeBase->Clicked = nullptr;
	}
}
