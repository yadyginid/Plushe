// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "MoveAwayTask.generated.h"


UCLASS()
class PLUSHE_API UMoveAwayTask : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UMoveAwayTask();

	UPROPERTY(EditAnywhere, Category="Blackboard")
	FBlackboardKeySelector TargetActorKey;   

	UPROPERTY(EditAnywhere, Category="Flee")
	float FleeDistance = 1000.f;            

	UPROPERTY(EditAnywhere, Category="Flee")
	float JitterRadius = 250.f;            

	UPROPERTY(EditAnywhere, Category="MoveTo")
	float AcceptanceRadius = 100.f;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
