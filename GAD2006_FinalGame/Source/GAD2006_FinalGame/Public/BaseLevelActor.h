// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseLevelActor.generated.h"

class UBoxComponent;

UCLASS()
class GAD2006_FINALGAME_API ABaseLevelActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseLevelActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "MyTriggers")
	UBoxComponent* Trigger;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "MyTriggers")
	UBoxComponent* SpawnLocation;

public:

	UBoxComponent* GetTrigger();
	UBoxComponent* GetSpawnLocation();
};
