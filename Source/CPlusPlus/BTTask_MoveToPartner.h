#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_MoveToPartner.generated.h"

UCLASS()
class CPLUSPLUS_API UBTTask_MoveToPartner : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UBTTask_MoveToPartner();

protected:
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

    UPROPERTY(EditAnywhere, Category = Blackboard)
    struct FBlackboardKeySelector TargetLocationKey;
};
