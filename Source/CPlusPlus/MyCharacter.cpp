// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	IsJumping = false;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AMyCharacter::TurnLeftRight(float value)
{
	AddControllerYawInput(value);
}

void AMyCharacter::TurnUpDown(float value)
{
	AddControllerPitchInput(value);
}

void AMyCharacter::MoveForwardBackward(float value)
{
	if (value == 0)
	{
		return;
	}

	const FRotator ControllerRotation = GetControlRotation();
	const FRotator YawRotation(0.0, ControllerRotation.Yaw, 0.0);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
	AddMovementInput(Direction, value);
}

void AMyCharacter::MoveLeftRight(float value)
{
	if (value == 0)
	{
		return;
	}

	const FRotator ControllerRotation = GetControlRotation();
	const FRotator YawRotation(0.0, ControllerRotation.Yaw, 0.0);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(Direction, value);
}

void AMyCharacter::MyJump()
{
	if (CanJump())
	{
		Jump();
	}

	IsJumping = true;
}

void AMyCharacter::MyStopJumping()
{
	StopJumping();
	IsJumping = false;
}

void AMyCharacter::Shoot()
{
	IsShooting = true;
	PlayMontageAndSetTimer(ShootingMontage);
}

void AMyCharacter::StopShooting()
{
	IsShooting = false;
}

void AMyCharacter::PlayMontageAndSetTimer(UAnimMontage* MontageToPlay)
{
	if (!GetCurrentMontage())
	{
		if (MontageToPlay)
		{
			GetCharacterMovement()->DisableMovement();

			int32 sectionIndex = ShootingMontage->GetSectionIndex("Default");
			int32 sectionLength = ShootingMontage->GetSectionLength(sectionIndex);

			PlayAnimMontage(MontageToPlay);

			GetWorldTimerManager().SetTimer(TimerHandle, this, &AMyCharacter::EnableWalk, sectionLength);
		}
	}
}

void AMyCharacter::EnableWalk()
{
	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (!PlayerInputComponent)
	{
		return;
	}

	PlayerInputComponent->BindAxis("TurnLeftRight", this, &AMyCharacter::TurnLeftRight);
	PlayerInputComponent->BindAxis("TurnUpDown", this, &AMyCharacter::TurnUpDown);

	PlayerInputComponent->BindAxis("MoveForwardBackward", this, &AMyCharacter::MoveForwardBackward);
	PlayerInputComponent->BindAxis("MoveLeftRight", this, &AMyCharacter::MoveLeftRight);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMyCharacter::MyJump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AMyCharacter::MyStopJumping);

		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Triggered, this, &AMyCharacter::Shoot);
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Completed, this, &AMyCharacter::StopShooting);
	}
}

bool AMyCharacter::GetIsJumping()
{
	return IsJumping;
}

bool AMyCharacter::GetIsShooting()
{
	return IsShooting;
}

void AMyCharacter::SpawnActor()
{
	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	GetWorld()->SpawnActor<AActor>(actorBPToSpawn, GetActorTransform(), spawnParams);
}