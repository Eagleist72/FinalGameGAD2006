// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseLevelActor.h"
#include "Components/BoxComponent.h"

// Sets default values
ABaseLevelActor::ABaseLevelActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseLevelActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (Trigger != nullptr)
		Trigger->bHiddenInGame = true;
}

// Called every frame
void ABaseLevelActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UBoxComponent* ABaseLevelActor::GetTrigger()
{
	return Trigger;
}

UBoxComponent* ABaseLevelActor::GetSpawnLocation()
{
	return SpawnLocation;
}

