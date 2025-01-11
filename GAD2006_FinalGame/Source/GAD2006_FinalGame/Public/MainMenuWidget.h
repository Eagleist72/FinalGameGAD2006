// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class GAD2006_FINALGAME_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	

protected:
    virtual void NativeConstruct() override;

private:
    UPROPERTY(meta = (BindWidget))
    class UButton* StartButton;

    UPROPERTY(meta = (BindWidget))
    class UButton* QuitButton;

    UFUNCTION()
    void OnStartClicked();

    UFUNCTION()
    void OnQuitClicked();
};
