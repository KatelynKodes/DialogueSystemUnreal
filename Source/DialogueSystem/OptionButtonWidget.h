// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OptionButtonWidget.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
/// <summary>
/// A UUser widget representing a dialogue option button
/// </summary>
class DIALOGUESYSTEM_API UOptionButtonWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	/// <summary>
	/// A refrence to the dialogue manager
	/// </summary>
	UPROPERTY(BlueprintReadWrite)
	class ADialogueManager* manager;

	/// <summary>
	/// The text being displayed on the option
	/// </summary>
	UPROPERTY(BlueprintReadWrite)
	FString OptionText;

	/// <summary>
	/// The conversation to be started if the option is clicked
	/// </summary>
	UPROPERTY(BlueprintReadWrite)
	class UDialogueDataAsset* branchingConvo;
};
