// Fill out your copyright notice in the Description page of Project Settings.


#include "Plushe/Public/AI/BasePlushe.h"

#include "AI/PlusheAIController.h"
#include "GameFramework/CharacterMovementComponent.h"

ABasePlushe::ABasePlushe()
{
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessAI = EAutoPossessAI::Disabled;
	AIControllerClass = APlusheAIController::StaticClass();

	bUseControllerRotationYaw = false;
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 200.0f, 0.0f);
	}
}

void ABasePlushe::BeginPlay()
{
	Super::BeginPlay();
}

void ABasePlushe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


