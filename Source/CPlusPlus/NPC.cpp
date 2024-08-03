#include "NPC.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Engine.h"

// Sets default values
ANPC::ANPC()
{
    PrimaryActorTick.bCanEverTick = true;

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    StaticMeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
    Super::BeginPlay();

    // Log to confirm BeginPlay is called
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("BeginPlay called on NPC"));
    }

    // Set the static mesh with a random color
    SetRandomColor();
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

void ANPC::SetRandomColor()
{
    if (StaticMeshComponent)
    {
        // Create a dynamic material instance
        UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(StaticMeshComponent->GetMaterial(0), this);
        if (DynamicMaterial)
        {
            // Set the color parameter of the material to a random color
            DynamicMaterial->SetVectorParameterValue("Color", GetRandomColor());
            StaticMeshComponent->SetMaterial(0, DynamicMaterial);
        }
    }
}

FLinearColor ANPC::GetRandomColor() const
{
    // Generate a random color
    float R = FMath::FRand();
    float G = FMath::FRand();
    float B = FMath::FRand();
    return FLinearColor(R, G, B);
}
