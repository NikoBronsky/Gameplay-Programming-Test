// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "HookComponent.generated.h"

class UCameraComponent;
class APTGrappleLine;
class APTHook;
class IPTHookInterface;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROGRAMMINGTEST_API UHookComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHookComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void SetGrappleMoving(bool NewState);
	void BuildHookAndGrapple(FHitResult Hit);
	void Reset();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Hook")
	void TryToGrab(UCameraComponent* Camera);

	// Cancel Grapple Connection if it exists
	UFUNCTION(BlueprintCallable, Category = "Hook")
	void RemoveGrapple();

	void TraceForHook(bool& bSuccess, FHitResult& Hit, UCameraComponent* Camera);


private:

	UPROPERTY(EditDefaultsOnly, Category = "Hook")
	float HookMaxDistance = 1500;
	UPROPERTY(EditAnywhere, Category = "Hook")
	float GrappleHookStrenght = 2000;
	bool BGrappleMoving;

	AActor* HookTarget;
	APTGrappleLine* GrappleLine;
	APTHook* HookMesh;

};
