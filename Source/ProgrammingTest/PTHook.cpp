// Fill out your copyright notice in the Description page of Project Settings.


#include "PTHook.h"

APTHook::APTHook()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT(" StaticMesh'/Game/ProgrammingTest/Hook/HookMesh.HookMesh'"));
	UStaticMesh* Asset = MeshAsset.Object;
	
	GetStaticMeshComponent()->SetStaticMesh(Asset);
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
}
