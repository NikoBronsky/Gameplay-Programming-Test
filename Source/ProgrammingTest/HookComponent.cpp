// Fill out your copyright notice in the Description page of Project Settings.


#include "HookComponent.h"
#include "Camera/CameraComponent.h"
#include "PTGrappleLine.h"
#include "CableComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "PTHook.h"

// Sets default values for this component's properties
UHookComponent::UHookComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHookComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UHookComponent::MovingToPoint(AActor* Target)
{
	if (Target != nullptr)
	{
	}
}

void UHookComponent::ResetMoving()
{

}

void UHookComponent::BuildHookAndGrapple(FHitResult Hit)
{
	FRotator HookRotation = UKismetMathLibrary::MakeRotationFromAxes(Hit.ImpactNormal, FVector (0,0,0), FVector (0,0,0));
	HookMesh = GetWorld()->SpawnActor<APTHook>(Hit.ImpactPoint, HookRotation);
	HookMesh->AttachToComponent(Hit.GetComponent(), FAttachmentTransformRules::KeepWorldTransform);
	GrappleLine = GetWorld()->SpawnActor<APTGrappleLine>(this->GetComponentLocation(), GetComponentRotation());
	GrappleLine->AttachToComponent(this, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	GrappleLine->CableComponent->EndLocation.X = 15;
	GrappleLine->CableComponent->SetAttachEndTo(HookMesh, NAME_None, "Socket");
}

// Called every frame
void UHookComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHookComponent::TraceForHook(bool& bSuccess, FHitResult& Hit, UCameraComponent* Camera)
{
	if (Camera != nullptr)
	{
		FVector StartPosition = Camera->GetComponentLocation();
		FVector EndPosition = Camera->GetForwardVector() * TraceRange + StartPosition;
		bSuccess = GetWorld()->LineTraceSingleByChannel(Hit, StartPosition, EndPosition, ECC_Visibility);
	}
}

void UHookComponent::TryToGrab(UCameraComponent* Camera)
{
	bool bSuccess;
	FHitResult Hit;
	TraceForHook(bSuccess, Hit, Camera);
	if (bSuccess)
	{
		HookTarget = Hit.GetActor();
		BuildHookAndGrapple(Hit);
		MovingToPoint(HookTarget);
	}
}
