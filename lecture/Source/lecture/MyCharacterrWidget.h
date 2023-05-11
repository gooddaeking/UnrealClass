// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyCharacterrWidget.generated.h"

/**
 * 
 */
UCLASS()
class LECTURE_API UMyCharacterrWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void BindHp(class UMyStatComponent* StatComp);

	void UpdateHp();
	
private:
	TWeakObjectPtr<class UMyStatComponent> CurrentStatComp;
	
	UPROPERTY(meta=(BindWidget))
	class UProgressBar* PB_HpBar;
};
