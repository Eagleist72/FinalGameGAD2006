// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (StartButton)
    {
        StartButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnStartClicked);
    }

    if (QuitButton)
    {
        QuitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnQuitClicked);
    }
}

void UMainMenuWidget::OnStartClicked()
{
    UGameplayStatics::OpenLevel(this, FName("GameMap"));
}

void UMainMenuWidget::OnQuitClicked()
{
    UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}