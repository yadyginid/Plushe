// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Data/AIDataAsset.h"
#include "PlusheAIController.generated.h"

class UAIDataAsset;
class UPlusheAIPerceptionComponent;

UCLASS()
class PLUSHE_API APlusheAIController : public AAIController
{
	GENERATED_BODY()

public:
	APlusheAIController();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Plushe|Config")
	UAIDataAsset* AIDataAsset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Plushe|Behavior")
	EPlusheState PlusheState = EPlusheState::Aggressive;

	void UpdatePlusheState(EPlusheState PlusheState);
	
protected:
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UPlusheAIPerceptionComponent* PlusheAIPerceptionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FName FocusOnKeyName = "EnemyActor";

private:
	void UpdateData();
};
