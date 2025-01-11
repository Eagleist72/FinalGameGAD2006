// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FinalCharacter.generated.h"

UCLASS()
class GAD2006_FINALGAME_API AFinalCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* SideViewCamera;

public:
	// Sets default values for this character's properties
	AFinalCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	void MoveRight(float value);

	// H�zl� ini� fonksiyonu
	void FastFall();

	// H�zl� ini� esnas�nda daha fazla yer�ekimi uygulamak i�in de�i�ken
	bool bIsFastFalling;

public:

	class UCameraComponent* GetSideViewCameraComponent() const
	{
		return SideViewCamera;
	}

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:

	float zPosition;
	FVector tempPos = FVector();

	bool CanMove;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> EndGameWidgetClass;

	UUserWidget* EndGameWidgetInstance;

};
