// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DialogueManager.generated.h"

UCLASS()
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
	UFUNCTION(CallInEditor)
	void startConversation(class UDialogueDataAsset* asset);
	
	/// <summary>
	/// A function called by the UI widget blueprint to update the text on the screen according to the
	/// current line of the conversation
	/// </summary>
	UFUNCTION(BlueprintCallable)
	void updateText(FString speakername, FString speakertext);

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
	UPROPERTY(BlueprintReadWrite)
	FString DialogueText;
	UPROPERTY(BlueprintReadWrite)
	FColor DialogueColor;
	UPROPERTY(BlueprintReadWrite)
	FString SpeakerName;

private:
	UPROPERTY(VisibleAnywhere)
	TArray<FString> _lines;

	class UDialogueDataAsset* _currentConvo;

	UPROPERTY(EditAnywhere)
	class UDialogueDataAsset* _debugConvo; //Delete this

	int _lineNum;
	bool _conversationStarted = false;

};
