// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_AIController.h"

#include "NPC.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"

ANPC_AIController::ANPC_AIController(FObjectInitializer const& ObjectInitializer)
{

}

void ANPC_AIController::SetBoolValueInBlackboard(FName Name, bool Value)
{
	UBlackboardComponent* BlackboardComp = GetBlackboardComponent();
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsBool(Name,Value);
	}
}

void ANPC_AIController::SetVectorValueInBlackboard(FName Name, FVector Value)
{
    UBlackboardComponent* BlackboardComp = GetBlackboardComponent();
    if (BlackboardComp)
    {
        BlackboardComp->SetValueAsVector(Name, Value);
    }
}


void ANPC_AIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    if (ANPC* const NPC = Cast<ANPC>(InPawn))
    {
        if (UBehaviorTree* const Tree = NPC->GetBehaviorTree())
        {
            if (UseBlackboard(Tree->BlackboardAsset, Blackboard))
            {
                RunBehaviorTree(Tree);
            }
        }
    }
}
