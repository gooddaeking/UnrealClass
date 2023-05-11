// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterrWidget.h"
#include "MyStatComponent.h"
#include "Components/ProgressBar.h"

void UMyCharacterrWidget::BindHp(UMyStatComponent* StatComp)
{
	CurrentStatComp = StatComp;
	StatComp->OnHpChanged.AddUObject(this, &UMyCharacterrWidget::UpdateHp);
}

void UMyCharacterrWidget::UpdateHp()
{
	if(CurrentStatComp.IsValid())
	{
		PB_HpBar->SetPercent(CurrentStatComp->GetHpRatio());
	}
}
