// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BasePlushe.generated.h"

class UAIDataAsset;
class UBehaviorTree;

UCLASS()
class PLUSHE_API ABasePlushe : public ACharacter
{
	GENERATED_BODY()

public:
	ABasePlushe();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
	UBehaviorTree* BehaviorTreeAsset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Plushe|Config")
	UAIDataAsset* AIDataAsset;
	
protected:
	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;
};
