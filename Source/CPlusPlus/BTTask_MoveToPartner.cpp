#include "BTTask_MoveToPartner.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "AIController.h"

UBTTask_MoveToPartner::UBTTask_MoveToPartner()
{
    NodeName = "Find Location For Meeting";
}

EBTNodeResult::Type UBTTask_MoveToPartner::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    AAIController* AIController = OwnerComp.GetAIOwner();
    if (!AIController) return EBTNodeResult::Failed;

    ACharacter* NPC = Cast<ACharacter>(AIController->GetPawn());
    if (!NPC) return EBTNodeResult::Failed;

    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    ACharacter* Partner = Cast<ACharacter>(BlackboardComp->GetValueAsObject("PartnerNPC"));
    if (!Partner) return EBTNodeResult::Failed;

    // Compute the midpoint location between the NPC and its partner
    FVector Midpoint = (NPC->GetActorLocation() + Partner->GetActorLocation()) / 2;
    Midpoint.Z = 90.212491;

    // Set the midpoint location on the blackboard
    BlackboardComp->SetValueAsVector(TargetLocationKey.SelectedKeyName, Midpoint);

    return EBTNodeResult::Succeeded;
}