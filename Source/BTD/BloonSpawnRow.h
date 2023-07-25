// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Bloon.h"
#include "BloonSpawnRow.generated.h"

USTRUCT()
struct BTD_API FBloonSpawnRow : public FTableRowBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<ABloon> BloonType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SpawnDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int SpawnCount;
};
