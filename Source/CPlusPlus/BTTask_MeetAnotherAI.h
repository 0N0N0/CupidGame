// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_MeetAnotherAI.generated.h"

/**
 * 
 */
UCLASS()
class CPLUSPLUS_API UBTTask_MeetAnotherAI : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	explicit UBTTask_MeetAnotherAI(FObjectInitializer const& ObjectInitializer);
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	bool bHasExecuted = false;
};
