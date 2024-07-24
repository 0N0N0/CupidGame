// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class CPLUSPLUS_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	UFUNCTION(BlueprintCallable, Category = "Abilities")
		void SpawnActor();

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> actorBPToSpawn;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool GetIsJumping();
	bool GetIsShooting();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void TurnLeftRight(float value);
	void TurnUpDown(float value);

	void MoveForwardBackward(float value);
	void MoveLeftRight(float value);

	void MyJump();
	void MyStopJumping();

	UPROPERTY(BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	bool IsJumping;

	void Shoot();
	void StopShooting();

	UPROPERTY(BlueprintReadOnly, Category = "Action", meta = (AllowPrivateAccess = "true"))
	bool IsShooting;

private:	
	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputAction* ShootAction;

	UPROPERTY(EditDefaultsOnly, Category = "Animation montage")
	UAnimMontage* ShootingMontage;

	void PlayMontageAndSetTimer(UAnimMontage* MontageToPlay);
	void EnableWalk();

	FTimerHandle TimerHandle;
};
