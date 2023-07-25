// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterWidget.h"

void UShooterWidget::SpawnDefender()
{
	FVector WorldLocation, WorldDirection;
	FVector2D Position = UWidgetLayoutLibrary::GetMousePositionOnViewport(GetWorld());
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->DeprojectScreenPositionToWorld(Position.X, Position.Y, WorldLocation, WorldDirection);
	FActorSpawnParameters SpawnParameters;
	WorldLocation = BTDGameModeBase->ConvertViewportPositionToGameCoordinates(WorldLocation);
	if (!BTDGameModeBase->Playing && BTDGameModeBase->isValidSpawnLocation(WorldLocation, 2.5))
		BTDGameModeBase->Defenders.Add(GetWorld()->SpawnActor<AShooter>(AShooter::StaticClass(), WorldLocation, FRotator(0, 0, 0), SpawnParameters));
}

void UShooterWidget::NativeConstruct()
{
	BTDGameModeBase = Cast<ABTDGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
}
