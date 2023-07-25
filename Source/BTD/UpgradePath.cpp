// Fill out your copyright notice in the Description page of Project Settings.


#include "UpgradePath.h"

UUpgrade* UUpgradePath::GetUpgrade(FString Name, FString Description, int Cost)
{
	UUpgrade* Upgrade = NewObject<UUpgrade>();
	Upgrade->Name = Name;
	Upgrade->Description = Description;
	Upgrade->Cost = Cost;
	return Upgrade;
}
