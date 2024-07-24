// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "MyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


void UMyAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Character = Cast<AMyCharacter>(TryGetPawnOwner());
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (Character == nullptr)
	{
		return;
	}

	FVector Velocity = Character->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();

	bIsInAir = Character->GetCharacterMovement()->IsFalling();

	//bIsInputAccelerating = Character->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;

	bIsJumping = Character->GetIsJumping();

	bIsShooting = Character->GetIsShooting();
}