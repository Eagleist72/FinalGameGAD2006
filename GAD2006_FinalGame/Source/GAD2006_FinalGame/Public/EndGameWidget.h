// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EndGameWidget.generated.h"

/**
 * 
 */
UCLASS()
class GAD2006_FINALGAME_API UEndGameWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
    virtual void NativeConstruct() override;

private:
    UFUNCTION()
    void OnRetryClicked();

    UFUNCTION()
    void OnQuitClicked();

    UPROPERTY(meta = (BindWidget))
    class UButton* RetryButton;

    UPROPERTY(meta = (BindWidget))
    class UButton* QuitButton;
};
