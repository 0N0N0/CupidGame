// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "BoxSpawner.generated.h"

UCLASS()
class CPLUSPLUS_API ABoxSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoxSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UBoxComponent* BoxSpawner;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> SpawnerClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AController> AIControllerClass;

	UPROPERTY(EditDefaultsOnly)
	int32 SpawnObjectCount = 1;

	UPROPERTY(EditDefaultsOnly)
	bool bShouldSpawnLoop = false;

	void Spawn();
};
