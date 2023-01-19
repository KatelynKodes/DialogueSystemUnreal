// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DialogueDataAsset.generated.h"

USTRUCT()
/// <summary>
/// A struct representing one line of dialogue contains a speakername and speaker text
/// also contains color variables to change the color of the text and textbox
/// </summary>
struct FLine
{
	GENERATED_USTRUCT_BODY()
	
	/// <summary>
	/// A string indicating the speaker of the text
	/// </summary>
	UPROPERTY(EditAnywhere)
	FString SpeakerName;
	
	/// <summary>
	/// A color value to set the textbox color to (can be used to differentiate between speakers)
	/// </summary>
	UPROPERTY(EditAnywhere)
	FColor TextBoxColor = FColor(0.0f, 0.0f, 0.0f, 255.0f);

	/// <summary>
	/// A color value to set the text color to (can be used to differentiate between speakers)
	/// </summary>
	UPROPERTY(EditAnywhere)
	FColor TextColor = FColor(0.0f, 0.0f, 0.0f, 255.0f);

	/// <summary>
	/// A string representing the actual line the speaker is saying
	/// </summary>
	UPROPERTY(EditAnywhere)
	FString SpeakerText;
};


USTRUCT()
/// <summary>
/// A struct representing an option, contains a string represnting the option title as well as a branching
/// dialogue data asset
/// </summary>
struct FOption
{
	GENERATED_USTRUCT_BODY()

	/// <summary>
	/// A string displaying the option text to be displayed on the button
	/// </summary>
	UPROPERTY(EditAnywhere)
	FString optionTitle;

	/// <summary>
	/// The conversation to be switched to when the option is selected
	/// </summary>
	UPROPERTY(EditAnywhere)
	class UDialogueDataAsset* BranchingConvo;
};

/**
 * 
 */
UCLASS()
/// <summary>
/// A dialogue data asset, contains dialogue information such as lines and options, also contains continued convo
/// in case the user would like to attach a continuing dialogue data asset
/// </summary>
class DIALOGUESYSTEM_API UDialogueDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	/// <summary>
	/// An array of line structs
	/// </summary>
	UPROPERTY(EditAnywhere)
	TArray<FLine> lines;

	/// <summary>
	/// A dialogue data asset pointer pointing to the next dialogue asset
	/// </summary>
	UPROPERTY(EditAnywhere)
	UDialogueDataAsset* ContinuedConvo;

	/// <summary>
	/// An array of option structs
	/// </summary>
	UPROPERTY(EditAnywhere)
	TArray<FOption> options;
};
