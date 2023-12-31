// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Upgrade.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class BTD_API UUpgrade : public UObject
{
	GENERATED_BODY()
public:
	UUpgrade();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Cost;

};
