// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_ClearUnderScore.generated.h"

/**
 * 
 */
UCLASS()
class SHIPSHOOTER_API UBTTask_ClearUnderScore : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_ClearUnderScore();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	
};
