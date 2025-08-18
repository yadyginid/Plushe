// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Task/MoveAwayTask.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UMoveAwayTask::UMoveAwayTask()
{
	NodeName = "MoveAwayTask";
}

EBTNodeResult::Type UMoveAwayTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AC = OwnerComp.GetAIOwner();
	if (!AC) return EBTNodeResult::Failed;

	APawn* Pawn = AC->GetPawn();
	UBlackboardComponent* BB = OwnerComp.GetBlackboardComponent();
	if (!Pawn || !BB) return EBTNodeResult::Failed;

	AActor* Target = Cast<AActor>(BB->GetValueAsObject(TargetActorKey.SelectedKeyName));
	if (!Target) return EBTNodeResult::Failed;

	const FVector SelfLoc = Pawn->GetActorLocation();
	const FVector TargetLoc = Target->GetActorLocation();
	FVector Dir = (SelfLoc - TargetLoc).GetSafeNormal();
	if (Dir.IsNearlyZero()) return EBTNodeResult::Failed;
	
	FVector Desired = SelfLoc + Dir * FleeDistance;
	
	FVector Goal = Desired;
	if (UNavigationSystemV1* Nav = FNavigationSystem::GetCurrent<UNavigationSystemV1>(Pawn))
	{
		FNavLocation Out;
		if (Nav->ProjectPointToNavigation(Desired, Out))
		{
			Goal = Out.Location;
		}
	}
	
	FAIMoveRequest Req;
	Req.SetGoalLocation(Goal);
	Req.SetAcceptanceRadius(AcceptanceRadius);
	Req.SetUsePathfinding(true);

	FNavPathSharedPtr Path;
	AC->MoveTo(Req, &Path);

	return EBTNodeResult::Succeeded;
}
