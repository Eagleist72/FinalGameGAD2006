// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnLevelActor.h"
#include "BaseLevelActor.h"
#include "Engine.h"
#include "Components/BoxComponent.h"

// Sets default values
ASpawnLevelActor::ASpawnLevelActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnLevelActor::BeginPlay()
{
	Super::BeginPlay();

	SpawnLevel(true);
	SpawnLevel(false);
	SpawnLevel(false);
	SpawnLevel(false);

	
}

// Called every frame
void ASpawnLevelActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnLevelActor::SpawnLevel(bool IsFirst)
{
	SpawnLocation = FVector(0.0f, 1000.0f, 0.0f);
	SpawnRotation = FRotator(0, 90, 0);

	if(!IsFirst)
	{
		ABaseLevelActor* LastLevel = LevelList.Last();
		SpawnLocation = LastLevel->GetSpawnLocation()->GetComponentTransform().GetTranslation();
	}

	RandomLevel = FMath::RandRange(1, 10);
	ABaseLevelActor* NewLevel = nullptr;

	if(RandomLevel == 1)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevelActor>(Level1, SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if(RandomLevel == 2)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevelActor>(Level2, SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 3)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevelActor>(Level3, SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 4)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevelActor>(Level4, SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 5)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevelActor>(Level5, SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 6)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevelActor>(Level6, SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 7)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevelActor>(Level7, SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 8)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevelActor>(Level8, SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 9)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevelActor>(Level9, SpawnLocation, SpawnRotation, SpawnInfo);
	}
	else if (RandomLevel == 10)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevelActor>(Level10, SpawnLocation, SpawnRotation, SpawnInfo);
	}

	if(NewLevel)
	{
		if (NewLevel->GetTrigger())
		{
			NewLevel->GetTrigger()->OnComponentBeginOverlap.AddDynamic(this, &ASpawnLevelActor::OnOverlapBegin);
		}
	}

	LevelList.Add(NewLevel);
	if (LevelList.Num() > 5)
	{
		LevelList.RemoveAt(0);
	}
}

void ASpawnLevelActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	SpawnLevel(false);
}

