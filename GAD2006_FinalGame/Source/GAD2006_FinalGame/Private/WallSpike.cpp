// Fill out your copyright notice in the Description page of Project Settings.


#include "WallSpike.h"


AWallSpike::AWallSpike()
{
	PrimaryActorTick.bCanEverTick = true;

	Speed = 400.0f;
}

void AWallSpike::BeginPlay()
{
	Super::BeginPlay();

	this->GetRootComponent()->ComponentVelocity = FVector(0, 25, 0);

	GetWorld()->GetTimerManager().SetTimer(SpeedIncreaseTimer, this, &AWallSpike::IncreaseSpeed, 10.0f, true);

}

void AWallSpike::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(GetActorLocation() + FVector(0, Speed* DeltaTime, 0), true);
}

void AWallSpike::IncreaseSpeed()
{
	Speed += 20.0f;

	UE_LOG(LogTemp, Warning, TEXT("WallSpike Speed Increased: %f"), Speed);
}
