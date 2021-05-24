// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/StaticMeshComponent.h>
#include "PTHookInterface.h"
#include "NativeActor.generated.h"

UCLASS(NotBlueprintable)
class PROGRAMMINGTEST_API ANativeActor : public AActor, public IPTHookInterface
{
	GENERATED_BODY()
	
public:	
	ANativeActor();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMeshComponent* Mesh;

protected:
	void Report(ACharacter* Character);


public:
	// My Code Below

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactions")
		void ExecutionActivate(ACharacter* Character);
	virtual void ExecutionActivate_Implementation(ACharacter* Character) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactions")
		float GetActivationDistance();
	virtual float GetActivationDistance_Implementation() override;


};
