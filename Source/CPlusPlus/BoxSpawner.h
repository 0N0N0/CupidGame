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

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> SpawnerClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AController> AIControllerClass;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* MaterialInterface;

	UPROPERTY(EditAnywhere)
	int32 SpawnObjectCount = 1;

	UPROPERTY(EditAnywhere)
	bool bShouldSpawnLoop = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UBoxComponent* BoxSpawner;

	void Spawn();
};
