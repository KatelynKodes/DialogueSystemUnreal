// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DialogueManager.generated.h"

UCLASS(Blueprintable)
/// <summary>
/// The DialogueManager is an actor that reads DialogueDataAsset data and storing it.
/// </summary>
class DIALOGUESYSTEM_API ADialogueManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADialogueManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/// <summary>
	/// Starts a conversation using a data asset of type DialogueDataAsset
	/// </summary>
	/// <param name="asset"></param>
	UFUNCTION(BlueprintCallable)
	void startConversation(class UDialogueDataAsset* asset);
	
	/// <summary>
	/// Updates the public text and color values according to the current line
	/// </summary>
	/// <param name="speakername">The value the SpeakerText variable has to be changed to</param>
	/// <param name="dialogue">The value the DialogueText variable has to be changed to</param>
	void updateText(FString speakername, FString dialogue);

	/// <summary>
	/// Returns if a conversation is currently happening
	/// </summary>
	/// <returns>True if a conversation is currently ongoing</returns>
	bool convoIsHappening() { return _convoIsHappening; }

	/// <summary>
	/// Returns how many options are available to the user
	/// </summary>
	/// <returns>An integer</returns>
	int optionNum() { return _optionNum; }

	/// <summary>
	/// Returns the private variable containing the option texts from the current conversation dialogue data
	/// asset
	/// </summary>
	/// <returns></returns>
	TArray<FString> optionText() { return _optionsText; }

public:
	/// <summary>
	/// Grabs the branching dialogue of an option
	/// </summary>
	UFUNCTION(BlueprintCallable)
	class UDialogueDataAsset* getOptionBranch(int index);

private:
	/// <summary>
	/// Goes to the next line of dialogue
	/// </summary>
	UFUNCTION(CallInEditor)
	void nextLine();

	/// <summary>
	/// Ends the conversation
	/// </summary>
	void endConversation();

public:
	/// <summary>
	/// Text that should be displayed in the speaker box
	/// </summary>
	FString SpeakerText;

	/// <summary>
	/// Text that should be displayed in the dialogue box
	/// </summary>
	FString DialogueText;

	/// <summary>
	/// The color of the box
	/// </summary>
	FLinearColor TextBoxColor;

	/// <summary>
	/// The color of the text
	/// </summary>
	FLinearColor TextColor;

private:
	/// <summary>
	/// The lines of the current dialogue data asset.
	/// </summary>
	TArray<FString> _lines;

	/// <summary>
	/// the current dialogue data asset.
	/// </summary>
	class UDialogueDataAsset* _currentConvo;

	UPROPERTY(EditAnywhere)
	/// <summary>
	/// The default DialogueDataAsset, will run this on start
	/// </summary>
	class UDialogueDataAsset* _debugConvo;

	/// <summary>
	/// The current line number the dialoguemanager is reading off of, used to make sure the dialogue manager
	/// doesn't go out of bounds on the line struct array in the current conversation
	/// </summary>
	int _lineNum;

	/// <summary>
	/// A boolean tracking if a conversation is happening 
	/// </summary>
	bool _convoIsHappening = false;

	//OPTIONS
	
	/// <summary>
	/// The number of options present in the current conversation
	/// </summary>
	int _optionNum = -1;

	/// <summary>
	/// An array of strings containing the option titles from the option struct array in the current conversation
	/// </summary>
	TArray<FString> _optionsText;
};
