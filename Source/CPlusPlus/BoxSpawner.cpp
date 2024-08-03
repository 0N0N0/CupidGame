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

	GetWorldTimerManager().SetTimer(TimerHandle, this, &ABoxSpawner::Spawn, SpawnObjectCount, bShouldSpawnLoop, 1.f);
}

void ABoxSpawner::Spawn()
{
    if (SpawnerClass && BoxSpawner)  // Check if SpawnerClass and BoxSpawner are valid
    {
        for (int a = 0; a < SpawnObjectCount; a++)
        {
            FRotator Rotation(0, 0, 0);
            FVector RandomLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), BoxSpawner->GetScaledBoxExtent());

            if (SpawnerClass->IsChildOf(ANPC::StaticClass()))
            {
                ANPC* SpawnedAI = GetWorld()->SpawnActor<ANPC>(SpawnerClass, RandomLocation, Rotation);
                if (SpawnedAI && AIControllerClass)  // Check if SpawnedAI and AIControllerClass are valid
                {
                    SpawnedAI->AIControllerClass = AIControllerClass;
                    SpawnedAI->SpawnDefaultController();
                }
            }
            else
            {
                GetWorld()->SpawnActor<AActor>(SpawnerClass, RandomLocation, Rotation);
            }
        }
    }
}
