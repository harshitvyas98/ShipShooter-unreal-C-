// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ClearUnderScore.h"
#include "BehaviorTree/BlackboardComponent.h"
UBTTask_ClearUnderScore::UBTTask_ClearUnderScore()
{
	NodeName = TEXT("Clear Blackboard Value");

}

EBTNodeResult::Type UBTTask_ClearUnderScore::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	OwnerComp.GetBlackboardComponent()-> ClearValue(GetSelectedBlackboardKey());

	return EBTNodeResult:: Succeeded;
}
