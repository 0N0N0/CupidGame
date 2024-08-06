// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_MeetAnotherAI.h"

#include "NPC_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"
#include <Kismet/GameplayStatics.h>
#include "MyCharacter.h"

UBTTask_MeetAnotherAI::UBTTask_MeetAnotherAI(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Meet another AI";
}

EBTNodeResult::Type UBTTask_MeetAnotherAI::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    // Check if the task has already been executed
    if (bHasExecuted)
    {
        return EBTNodeResult::Succeeded;
    }

    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (!BlackboardComp)
    {
        return EBTNodeResult::Failed;
    }

    AMyCharacter* Character = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    if (!Character)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Player character is null or not of type AMyCharacter"));
        }
        return EBTNodeResult::Failed;
    }

    FVector Location = Character->GetLocationForAIMeeting();
    if (Location.IsZero())
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("AI meeting location is invalid"));
        }
        return EBTNodeResult::Failed;
    }

    BlackboardComp->SetValueAsVector(GetSelectedBlackboardKey(), Location);

    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Set blackboard key location to %s"), *Location.ToString()));
    }

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);

    // Mark the task as executed
    bHasExecuted = true;

    return EBTNodeResult::Succeeded;
}
