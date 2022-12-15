// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogueUIWidget.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class DIALOGUESYSTEM_API UDialogueUIWidget : public UUserWidget
{
	GENERATED_BODY()
	
private:
	void NativeConstruct() override;
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	/// <summary>
	/// Updates the text being displayed on screen
	/// </summary>
	void UpdateText();

public:
	UPROPERTY(BlueprintReadWrite)
	FString SpeakerBoxText;

	UPROPERTY(BlueprintReadWrite)
	FString DialogueBoxText;

	UPROPERTY(BlueprintReadWrite)
	FLinearColor BoxColor;

	UPROPERTY(BlueprintReadWrite)
	FLinearColor TextColor;

private:
	UPROPERTY(VisibleAnywhere)
	class ADialogueManager* _dialogueManager;
};
