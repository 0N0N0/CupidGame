#include "NPC.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Engine.h"
#include "NPC_AIController.h"
#include "MyCharacter.h"

// Sets default values
ANPC::ANPC()
{
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ANPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

UBehaviorTree* ANPC::GetBehaviorTree() const
{
    return Tree;
}

void ANPC::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this) && OtherActor->ActorHasTag("NPC"))
    {
        AMyCharacter* MyCharacter = Cast<AMyCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
        if (MyCharacter)
        {
            MyCharacter->DisappearNPCs();
        }
    }
}

ANPC_AIController* ANPC::GetAIController() const
{
    ANPC_AIController* AIController = Cast<ANPC_AIController>(GetController());
    if (AIController)
    {
        return AIController;
    }
    return nullptr;
}

void ANPC::SetColor(FLinearColor newColor)
{
    Color = newColor;
}

FLinearColor ANPC::GetColor()
{
    return Color;
}
