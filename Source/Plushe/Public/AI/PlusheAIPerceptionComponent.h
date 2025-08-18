// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "PlusheAIPerceptionComponent.generated.h"


UCLASS()
class PLUSHE_API UPlusheAIPerceptionComponent : public UAIPerceptionComponent
{
	GENERATED_BODY()

public:
	AActor* GetClosestEnemy() const;
};
