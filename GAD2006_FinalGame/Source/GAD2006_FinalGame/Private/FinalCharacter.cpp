// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Spikes.h"
#include "WallSpike.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine.h"

// Sets default values
AFinalCharacter::AFinalCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Overlap);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	SideViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Side View Camera"));
	SideViewCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
	
	GetCharacterMovement()->GravityScale = 2.0f;
	GetCharacterMovement()->AirControl = 0.8f;
	GetCharacterMovement()->JumpZVelocity = 1000.0f;
	GetCharacterMovement()->GroundFriction = 3.0f;
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	GetCharacterMovement()->MaxFlySpeed = 600.0f;

	tempPos = GetActorLocation();
	zPosition = tempPos.Z + 300.0f;

	bIsFastFalling = false;
}

// Called when the game starts or when spawned
void AFinalCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AFinalCharacter::OnOverlapBegin);
	
	CanMove = true;

}

// Called every frame
void AFinalCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsFastFalling && GetCharacterMovement()->IsFalling() == false)
	{
		// Yere indiðimizde yerçekimi eski haline dönsün
		bIsFastFalling = false;
		GetCharacterMovement()->GravityScale = 2.0f; // Eski yerçekimi deðeri
	}

	tempPos = GetActorLocation();
	tempPos.X -= 850.0f;
	tempPos.Z = zPosition;
	SideViewCamera->SetWorldLocation(tempPos);

}

// Called to bind functionality to input
void AFinalCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("FastFall", IE_Pressed, this, &AFinalCharacter::FastFall);

	PlayerInputComponent->BindAxis("MoveRight", this, &AFinalCharacter::MoveRight);
}

void AFinalCharacter::MoveRight(float value)
{
	if(CanMove)
	{
		AddMovementInput(FVector(0.0f, 1.0f, 0.0f), value);
	}
}

void AFinalCharacter::FastFall()
{
	// Karakterin havada olduðunu kontrol et
	if (!GetCharacterMovement()->IsFalling())
	{
		return;
	}

	bIsFastFalling = true;	

	GetCharacterMovement()->GravityScale = 5.0f;


	LaunchCharacter(FVector(0.0f, 0.0f, -300.0f), true, true);
}

void AFinalCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
	bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor !=nullptr)
	{
		ASpikes* WallSpike = Cast<AWallSpike>(OtherActor);
		ASpikes* Spike = Cast<ASpikes>(OtherActor);

		if(WallSpike || Spike)
		{
			GetMesh()->Deactivate();
			GetMesh()->SetVisibility(false);

			CanMove = false;

			if (EndGameWidgetClass && !EndGameWidgetInstance)
			{
				EndGameWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), EndGameWidgetClass);
				if (EndGameWidgetInstance)
				{
					EndGameWidgetInstance->AddToViewport();

					APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
					if (PlayerController)
					{
						PlayerController->bShowMouseCursor = true;
						PlayerController->SetInputMode(FInputModeUIOnly());
					}
				}
			}
		}
	}
}

