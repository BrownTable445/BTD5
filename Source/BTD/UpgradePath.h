// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Upgrade.h"
#include "UpgradePath.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class BTD_API UUpgradePath : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UUpgrade*> Upgrades;
	UFUNCTION(BlueprintCallable)
		UUpgrade* GetUpgrade(FString Name, FString Description, int Cost);
	
};
