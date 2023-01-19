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
	/*UFUNCTION(BlueprintCallable)
	void attachOnClickMethod();*/
public:
	UPROPERTY(BlueprintReadWrite)
	FString OptionText;

	UPROPERTY(BlueprintReadWrite)
	class UButton* ButtonObject;

	UPROPERTY(BlueprintReadWrite)
	class UDialogueDataAsset* branchingConvo;
};
