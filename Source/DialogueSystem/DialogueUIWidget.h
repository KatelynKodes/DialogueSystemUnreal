// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogueUIWidget.generated.h"

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
	void updateText();

	/// <summary>
	/// sets the UI to be either visible or hidden depending on the boolean value passed in
	/// </summary>
	/// <param name="value">if true, displays the UI. If false, hides the UI</param>
	void displayUI(bool value);

	/// <summary>
	/// Adds options from the current dialogue to the option list
	/// </summary>
	/// <param name="optionNum">the number of options</param>
	void addOptions();


	void displayOptions();

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayOptions();

public:
	UPROPERTY(BlueprintReadWrite)
	FString SpeakerBoxText;

	UPROPERTY(BlueprintReadWrite)
	FString DialogueBoxText;

	UPROPERTY(BlueprintReadWrite)
	FLinearColor BoxColor;

	UPROPERTY(BlueprintReadWrite)
	FLinearColor TextColor;

	UPROPERTY(BlueprintReadWrite)
	TArray<class UOptionButtonWidget*> OptionButtons = TArray<class UOptionButtonWidget*>();

private:
	class ADialogueManager* _dialogueManager;
	bool _displayingUI = false;
	bool _displayingOptions = false;

};
