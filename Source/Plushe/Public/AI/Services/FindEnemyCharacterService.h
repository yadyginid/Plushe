// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "FindEnemyCharacterService.generated.h"


UCLASS()
class PLUSHE_API UFindEnemyCharacterService : public UBTService
{
	GENERATED_BODY()

public:
	UFindEnemyCharacterService();
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FBlackboardKeySelector EnemyActorKey;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
