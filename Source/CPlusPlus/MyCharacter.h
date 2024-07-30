// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "EnhancedInputComponent.h"
#include "InputAction.h"

#include "MyCharacter.generated.h"

UCLASS()
class CPLUSPLUS_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool GetIsJumping();
	bool GetIsShooting();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void TurnLeftRight(const FInputActionValue& Value);
	void TurnUpDown(const FInputActionValue& Value);

	void MoveForwardBackward(const FInputActionValue& Value);
	void MoveLeftRight(const FInputActionValue& Value);

	void MyJump();
	void MyStopJumping();

	UPROPERTY(BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	bool bIsJumping;

	void Shoot();
	void StopShooting();

	UPROPERTY(BlueprintReadOnly, Category = "Action", meta = (AllowPrivateAccess = "true"))
	bool bIsShooting;

private:	
	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputAction* ShootAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputAction* TurnLeftRightAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	float TurnLeftRightRate = 0.1f;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputAction* TurnUpDownAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	float TurnUpDownRate = 0.1f;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputAction* MoveForwardBackwardAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputAction* MoveLeftRightAction;


	UPROPERTY(EditDefaultsOnly, Category = "Animation montage")
	UAnimMontage* ShootingMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Bullet")
	TSubclassOf<AActor> BulletBP;

	UPROPERTY(EditDefaultsOnly, Category = "Bullet")
	FVector Offset = FVector(20, 150, 25);

	UPROPERTY(EditDefaultsOnly, Category = "Bullet")
	FVector Scale = FVector(0.1, 0.1, 0.1);


	void PlayMontageAndSetTimer(UAnimMontage* MontageToPlay);
	void EnableWalk();

	FTimerHandle TimerHandle;
	FTimerHandle TimerHandleForBullet;


	void SpawnBullet();
	void LineTrace();

	TSubclassOf<class UUserWidget> ScopeWidgetClass;
};
