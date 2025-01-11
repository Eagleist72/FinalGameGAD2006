// Fill out your copyright notice in the Description page of Project Settings.


#include "EndGameWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UEndGameWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (RetryButton)
    {
        RetryButton->OnClicked.AddDynamic(this, &UEndGameWidget::OnRetryClicked);
    }

    if (QuitButton)
    {
        QuitButton->OnClicked.AddDynamic(this, &UEndGameWidget::OnQuitClicked);
    }
}

void UEndGameWidget::OnRetryClicked()
{
    UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
}

void UEndGameWidget::OnQuitClicked()
{
    UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}
