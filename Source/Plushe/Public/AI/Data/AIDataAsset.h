// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AIDataAsset.generated.h"

UENUM(BlueprintType)
enum class EPlusheState : uint8
{
	Aggressive UMETA(DisplayName = "Aggressive"),
	Fearful    UMETA(DisplayName = "Fearful"),
	Friendly   UMETA(DisplayName = "Friendly")
};

UCLASS(BlueprintType)
class PLUSHE_API UAIDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Plushe|Movement")
	float MoveSpeed = 300.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Plushe|Perception")
	float PerceptionRadius = 1200.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Plushe|Behavior")
	EPlusheState PlusheState = EPlusheState::Aggressive;
};
