// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OptionActions.generated.h"

DECLARE_DELEGATE_OneParam(FBranchingConvo, class UDialogueDataAsset);


/**
 * 
 */
UCLASS()
class DIALOGUESYSTEM_API UOptionActions : public UObject
{
	GENERATED_BODY()
public:
	void hideOptions();
private:
	class UDialogueUIWidget* _dialogueUI;
	class ADialogueManager* _managerActor;
};
