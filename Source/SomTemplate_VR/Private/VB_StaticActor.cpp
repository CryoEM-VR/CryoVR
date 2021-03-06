// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.
//Written by Jun Zhang, May 2019

#include "VB_StaticActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AVB_StaticActor::AVB_StaticActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	m_isOn = false;

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetGenerateOverlapEvents(false);
	meshComp->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	meshComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	RootComponent = meshComp;

	shapeComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionShape"));
	shapeComp->SetGenerateOverlapEvents(true);
	shapeComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	shapeComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	shapeComp->SetupAttachment(meshComp);

}

// Called when the game starts or when spawned
void AVB_StaticActor::BeginPlay()
{
	Super::BeginPlay();

}

bool AVB_StaticActor::getState()
{
	return m_isOn;
}

void AVB_StaticActor::setState(bool newState)
{
	m_isOn = newState;
}

USceneComponent * AVB_StaticActor::GetComponentByIndex(int indexComp)
{
	if (indexComp == 0)
		return meshComp;
	else if (indexComp == 1)
		return shapeComp;

	return nullptr;
}

// Called every frame
void AVB_StaticActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
