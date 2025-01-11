// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinPickUpActor.h"

#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
ACoinPickUpActor::ACoinPickUpActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ColliderComponent = CreateDefaultSubobject<USphereComponent>("ColliderComponent");
	SetRootComponent(ColliderComponent);
	ColliderComponent->SetGenerateOverlapEvents(true);
	ColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	ColliderComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	ColliderComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	ColliderComponent->OnComponentBeginOverlap.AddDynamic(this, &ACoinPickUpActor::OnBeginOverlapComponentEvent);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(ColliderComponent);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshComponent->SetGenerateOverlapEvents(false);

	RotatingMovementComponent = CreateDefaultSubobject<URotatingMovementComponent>("RotatingMovementComponent");
}

void ACoinPickUpActor::OnBeginOverlapComponentEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!Cast<ACharacter>(OtherActor)) return;

	Destroy();
}

// Called when the game starts or when spawned
void ACoinPickUpActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoinPickUpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

