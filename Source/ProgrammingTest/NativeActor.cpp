// Fill out your copyright notice in the Description page of Project Settings.


#include "NativeActor.h"
#include <GameFramework/Character.h>

ANativeActor::ANativeActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/VREditor/BasicMeshes/SM_Ball_01"));

	if (MeshAsset.Succeeded())
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}
}

void ANativeActor::Report(ACharacter* Character)
{
	check(GetClass()->IsNative());

	if (IsValid(Character))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("%s: executing with %s"), *GetName(), *Character->GetName()));
	}
	else
	{
		UE_LOG(LogBlueprintUserMessages, Error, TEXT("%s: argument passed to Report is invalid"), *GetName());
	}
}