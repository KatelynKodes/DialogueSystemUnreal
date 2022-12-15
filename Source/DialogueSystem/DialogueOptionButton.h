// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "DialogueOptionButton.generated.h"

/**
 * 
 */
UCLASS()
class DIALOGUESYSTEM_API UDialogueOptionButton : public UButton
{
	GENERATED_BODY()

public:
	void OnCreationFromPalette() override;

private:

private:
	UPROPERTY(VisibleAnywhere)
	class UTextBlock* _buttonText;
};
