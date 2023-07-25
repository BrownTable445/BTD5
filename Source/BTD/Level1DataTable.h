// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Level1DataTable.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class BTD_API ULevel1DataTable : public UDataTable
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		int Bloon;
	UPROPERTY(EditAnywhere)
		float SpawnBloonDelay;
};
