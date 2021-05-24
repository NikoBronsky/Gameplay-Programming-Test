// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/StaticMeshComponent.h>
#include "PTHookInterface.h"
#include "NativeActor.generated.h"

UCLASS(NotBlueprintable)
class PROGRAMMINGTEST_API ANativeActor : public AActor, public UPTHookInterface
{
	GENERATED_BODY()
	
public:	
	ANativeActor();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMeshComponent* Mesh;

protected:
	void Report(ACharacter* Character);

	/*void ExecutionActivate_Implementation(ACharacter* Character);*/

};
