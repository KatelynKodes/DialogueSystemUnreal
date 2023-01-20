// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogueUIWidget.generated.h"

UCLASS(Blueprintable)
/// <summary>
/// The job of the DialogueUI wigdet is to take information fron the DialogueManager actor in the scene and display
/// it onto the users screen
/// </summary>
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

	/// <summary>
	/// Calls the AddOptions method and the OnDisplayOptions event
	/// </summary>
	void displayOptions();

	/// <summary>
	/// Removes options from screen then sets the option array to a new array
	/// </summary>
	void hideOptions();

public:
	UFUNCTION(BlueprintImplementableEvent)
	/// <summary>
	/// An event implimented in blueprints, used to display the option buttons to the screen
	/// </summary>
	void OnDisplayOptions();

	/// <summary>
	/// An event implimented in blueprints, used to remove the option buttons from the screen
	/// </summary>
	UFUNCTION(BlueprintImplementableEvent)
	void OnHideOptions();

public:
	UPROPERTY(BlueprintReadWrite)
	/// <summary>
	/// The string containing the speaker name
	/// </summary>
	FString SpeakerBoxText;

	UPROPERTY(BlueprintReadWrite)
	/// <summary>
	/// The string containing the text to be displayed in the dialoguebox
	/// </summary>
	FString DialogueBoxText;

	UPROPERTY(BlueprintReadWrite)
	/// <summary>
	/// The color the textbox will be
	/// </summary>
	FLinearColor BoxColor;

	UPROPERTY(BlueprintReadWrite)
	/// <summary>
	/// The color the text will be
	/// </summary>
	FLinearColor TextColor;

	UPROPERTY(BlueprintReadWrite)
	/// <summary>
	/// An array of optionbutton widgets representing the buttons to be displayed
	/// </summary>
	TArray<class UOptionButtonWidget*> OptionButtons = TArray<class UOptionButtonWidget*>();

	UPROPERTY(BlueprintReadWrite)
	/// <summary>
	/// A refrence to the dialogue manager in the scene
	/// </summary>
	class ADialogueManager* _dialogueManager;

private:
	/// <summary>
	/// A boolean checking if UI is displayed
	/// </summary>
	bool _displayingUI = false;

	/// <summary>
	/// A boolean checking if options are being displayed
	/// </summary>
	bool _displayingOptions = false;

};
