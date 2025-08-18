// Fill out your copyright notice in the Description page of Project Settings.


#include "Plushe/Public/AI/PlusheAIPerceptionComponent.h"

#include "AIController.h"
#include "Perception/AISense_Sight.h"
#include "Plushe/PlusheCharacter.h"

AActor* UPlusheAIPerceptionComponent::GetClosestEnemy() const
{
	TArray<AActor*> PercieveActors;
	GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), PercieveActors);
	if (PercieveActors.Num() == 0)
	{
		if (PercieveActors.Num() == 0) return nullptr;
	}

	const auto Controller = Cast<AAIController>(GetOwner());
	if (!Controller) return nullptr;

	const auto Pawn = Controller->GetPawn();
	if (!Pawn) return nullptr;

	AActor* EnemyCharacter = nullptr;
	
	for (const auto PercieveActor : PercieveActors)
	{
		if(const auto PlusheCharacter = Cast<APlusheCharacter>(PercieveActor))
		{
			EnemyCharacter = PlusheCharacter;
		}
	}
	return EnemyCharacter;
}
