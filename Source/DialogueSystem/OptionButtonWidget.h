// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OptionButtonWidget.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class DIALOGUESYSTEM_API UOptionButtonWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite)
	class ADialogueManager* manager;

	UPROPERTY(BlueprintReadWrite)
	FString OptionText;

	UPROPERTY(BlueprintReadWrite)
	class UButton* ButtonObject;

	UPROPERTY(BlueprintReadWrite)
	class UDialogueDataAsset* branchingConvo;
};
