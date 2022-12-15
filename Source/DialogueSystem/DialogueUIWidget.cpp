// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueUIWidget.h"
#include "DialogueManager.h"
#include "Kismet/GameplayStatics.h" 

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
}

void UDialogueUIWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (_dialogueManager->ConvoIsHappening())
	{
		UpdateText();
	}
}

void UDialogueUIWidget::UpdateText()
{
	SpeakerBoxText = _dialogueManager->SpeakerText;
	DialogueBoxText = _dialogueManager->DialogueText;
	BoxColor = _dialogueManager->TextBoxColor;
	TextColor = _dialogueManager->TextColor;
}
