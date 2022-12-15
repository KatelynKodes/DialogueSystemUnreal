// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DialogueDataAsset.generated.h"

USTRUCT()
struct FLine
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere)
	FString SpeakerName;
	
	UPROPERTY(EditAnywhere)
	FColor TextBoxColor = FColor(0.0f, 0.0f, 0.0f, 255.0f);

	UPROPERTY(EditAnywhere)
	FColor TextColor = FColor(0.0f, 0.0f, 0.0f, 255.0f);

	UPROPERTY(EditAnywhere)
	FString SpeakerText;
};

USTRUCT()
struct FOption
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	FString optionTitle;
};

/**
 * 
 */
UCLASS()
class DIALOGUESYSTEM_API UDialogueDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	TArray<FLine> lines;

	UPROPERTY(EditAnywhere)
	UDialogueDataAsset* branchingConvo;

	UPROPERTY(EditAnywhere)
	TArray<FOption> options;
};
