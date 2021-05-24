// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PTTowerDA.generated.h"

/**
 * 
 */
UCLASS()
class PROGRAMMINGTEST_API UPTTowerDA : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Duration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float GravityScale;
	
};
