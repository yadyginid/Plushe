// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/PlusheAIController.h"
#include "BrainComponent.h"
#include "AI/BasePlushe.h"
#include "AI/PlusheAIPerceptionComponent.h"
#include "AI/Data/AIDataAsset.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Perception/AISenseConfig_Sight.h"

APlusheAIController::APlusheAIController()
{
	PlusheAIPerceptionComponent = CreateDefaultSubobject<UPlusheAIPerceptionComponent>("PlusheAIPerceptionComponent");
	SetPerceptionComponent(*PlusheAIPerceptionComponent);
	
	bWantsPlayerState = true;
}

void APlusheAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (const auto BasePlushe = Cast<ABasePlushe>(InPawn))
	{
		RunBehaviorTree(BasePlushe->BehaviorTreeAsset);
		GetBrainComponent()->GetBlackboardComponent()->SetValueAsVector("InitPoint", GetPawn()->GetActorLocation());
	}

	UpdateData();
}

void APlusheAIController::UpdateData()
{
	auto BasePlushe = Cast<ABasePlushe>(GetPawn());
	if(!BasePlushe) return;

	const auto AIDataAsset = BasePlushe->AIDataAsset;
	if(!AIDataAsset) return;

	const auto BaseCharacter = Cast<ACharacter>(GetPawn());
	if(!BaseCharacter) return;

	const auto DominantSense = PlusheAIPerceptionComponent->GetDominantSense();
	if(!DominantSense) return;

	FAISenseID SenseId = UAISense::GetSenseID(UAISense_Sight::StaticClass());
	
	auto SenseConfig = PlusheAIPerceptionComponent->GetSenseConfig(SenseId);
	if(!SenseConfig) return;
	
	if (auto SightConfig = Cast<UAISenseConfig_Sight>(SenseConfig))
	{
		SightConfig->SightRadius      = AIDataAsset->PerceptionRadius;
		SightConfig->LoseSightRadius  = AIDataAsset->PerceptionRadius * 1.2f;
		
		PlusheAIPerceptionComponent->RequestStimuliListenerUpdate();
	}
	
	BaseCharacter->GetCharacterMovement()->MaxWalkSpeed = AIDataAsset->MoveSpeed;

	UpdatePlusheState(AIDataAsset->PlusheState);
}

void APlusheAIController::UpdatePlusheState(EPlusheState NewPlusheState)
{
	PlusheState = NewPlusheState;
	auto BlackboardComponent = GetBrainComponent()->GetBlackboardComponent();
	if(!BlackboardComponent) return;
	
	BlackboardComponent->SetValueAsEnum("PlusheState", static_cast<uint8>(PlusheState));
	if(NewPlusheState == EPlusheState::Tamed)
	{
		BlackboardComponent->SetValueAsObject("Master", GetWorld()->GetFirstPlayerController()->GetCharacter());
	}
}

