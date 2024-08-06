// Fill out your copyright notice in the Description page of Project Settings.


#include "BoxSpawner.h"
#include "Kismet/KismetMathLibrary.h"
#include "NPC.h"

// Sets default values
ABoxSpawner::ABoxSpawner()
{
	BoxSpawner = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawner"));
	BoxSpawner->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void ABoxSpawner::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle TimerHandle;

	GetWorldTimerManager().SetTimer(TimerHandle, this, &ABoxSpawner::Spawn, SpawnObjectCount, bShouldSpawnLoop, 2.f);
}

void ABoxSpawner::Spawn()
{
    if (SpawnerClass && BoxSpawner)
    {
        TArray<FLinearColor> Colors;

        if (SpawnerClass->IsChildOf(ANPC::StaticClass()))
        {
            for (int i = 0; i < SpawnObjectCount / 2; i++)
            {
                FLinearColor Color = FLinearColor::MakeRandomColor();
                Colors.Add(Color);
                Colors.Add(Color);
            }

            if (SpawnObjectCount % 2 != 0)
            {
                Colors.Add(FLinearColor::MakeRandomColor());
            }
        }

        for (int a = 0; a < SpawnObjectCount; a++)
        {
            FRotator Rotation(0, 0, 0);
            FVector RandomLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), BoxSpawner->GetScaledBoxExtent());

            if (SpawnerClass->IsChildOf(ANPC::StaticClass()))
            {
                ANPC* SpawnedAI = GetWorld()->SpawnActor<ANPC>(SpawnerClass, RandomLocation, Rotation);
                if (SpawnedAI && AIControllerClass)
                {
                    SpawnedAI->AIControllerClass = AIControllerClass;
                    SpawnedAI->SpawnDefaultController();

                    UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(MaterialInterface, this);

                    if (DynamicMaterial)
                    {
                        DynamicMaterial->SetVectorParameterValue(FName("BaseColor"), Colors[a]);

                        SpawnedAI->GetMesh()->SetMaterial(0, DynamicMaterial);

                        SpawnedAI->SetColor(Colors[a]);
                    }
                }
            }
            else
            {
                auto Actor = GetWorld()->SpawnActor<AActor>(SpawnerClass, RandomLocation, Rotation);
            }
        }
    }
}