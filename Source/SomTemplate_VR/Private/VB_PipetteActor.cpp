// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "VB_PipetteActor.h"
#include "Components/Spherecomponent.h"
#include "Kismet/GameplayStatics.h"
#include "Public/Engine.h"
#include "VB_SampleTubeActor.h"

AVB_PipetteActor::AVB_PipetteActor()
{
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &AVB_PipetteActor::OnOverlapBegin);

	

}


void AVB_PipetteActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	
	if (Cast<AVB_SampleTubeActor>(OtherActor) != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Activated"));
	}

}



//This is an potential function that may be used in the future
/*
void AVB_PipetteActor::OnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Log, TEXT("Activated"));
}
*/