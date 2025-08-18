// Fill out your copyright notice in the Description page of Project Settings.


#include "Plushe/Public/AI/Services/FindEnemyCharacterService.h"

#include "AIController.h"
#include "ProjectUtils.h"
#include "AI/PlusheAIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

UFindEnemyCharacterService::UFindEnemyCharacterService()
{
	NodeName = "FindEnemyPlayer";
}

void UFindEnemyCharacterService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	const auto Blackboard = OwnerComp.GetBlackboardComponent();

	if (Blackboard)
	{
		const auto Controller = OwnerComp.GetAIOwner();
		const auto PerseptionComponent = ProjectUtils::GetSTUPlayerComponent<UPlusheAIPerceptionComponent>(Controller);
		if (PerseptionComponent)
		{
			Blackboard->SetValueAsObject(EnemyActorKey.SelectedKeyName, PerseptionComponent->GetClosestEnemy());
		}
	}
	
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
