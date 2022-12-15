// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueUIWidget.h"
#include "DialogueManager.h"
#include "Kismet/GameplayStatics.h"
#include <Components/Image.h>

void UDialogueUIWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (!_dialogueManager)
	{
		//Finds the dialogue manager actor in the scene 
		//THERE SHOULD ONLY BE ONE DIALOGUE MANAGER
		AActor* ManagerActor = UGameplayStatics::GetActorOfClass(GetWorld(), ADialogueManager::StaticClass());

		_dialogueManager = Cast<ADialogueManager>(ManagerActor);

	}

	displayUI(_displayingUI);
}

void UDialogueUIWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (_dialogueManager->convoIsHappening())
	{
		if (!_displayingUI)
			displayUI(true);

		updateText();
	}
	else
	{
		if(_displayingUI)
			displayUI(false);
	}
}

void UDialogueUIWidget::updateText()
{
	SpeakerBoxText = _dialogueManager->SpeakerText;
	DialogueBoxText = _dialogueManager->DialogueText;
	BoxColor = _dialogueManager->TextBoxColor;
	TextColor = _dialogueManager->TextColor;
}

void UDialogueUIWidget::displayUI(bool value)
{
	if (value)
	{
		//Set the UI to be visible
		BoxColor.A = 1.0f;

		_displayingUI = true;
	}
	else
	{
		//Clear the text
		SpeakerBoxText = "";
		DialogueBoxText = "";

		//Set the UI to be invisible
		BoxColor.A = 0.0f;

		_displayingUI = false;
	}
}
