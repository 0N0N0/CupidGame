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
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	bIsJumping = false;
	bIsShooting = false;

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

	bIsJumping = true;
}

void AMyCharacter::MyStopJumping()
{
	StopJumping();
	bIsJumping = false;
}

void AMyCharacter::Shoot()
{
	if (!bIsShooting && !GetCharacterMovement()->IsFalling())
	{
		bIsShooting = true;

		PlayMontageAndSetTimer(ShootingMontage);

		GetWorldTimerManager().SetTimer(TimerHandleForBullet, this, &AMyCharacter::SpawnBullet, 1.0f, false);
	}
}

void AMyCharacter::StopShooting()
{
	
}

void AMyCharacter::PlayMontageAndSetTimer(UAnimMontage* MontageToPlay)
{
	if (!GetCurrentMontage())
	{
		if (MontageToPlay)
		{
			GetCharacterMovement()->DisableMovement();

			int32 sectionIndex = ShootingMontage->GetSectionIndex("Default");
			float sectionLength = ShootingMontage->GetSectionLength(sectionIndex);

			PlayAnimMontage(MontageToPlay);

			GetWorldTimerManager().SetTimer(TimerHandle, this, &AMyCharacter::EnableWalk, sectionLength);
		}
	}
}

void AMyCharacter::EnableWalk()
{
	bIsShooting = false;

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
	return bIsJumping;
}

bool AMyCharacter::GetIsShooting()
{
	return bIsShooting;
}

void AMyCharacter::SpawnBullet()
{
	//GEngine->AddOnScreenDebugMessage(-1, 100.f, FColor::Red, TEXT("BulletSpawned!"));
	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	FRotator actorRotation = GetActorTransform().GetRotation().GetForwardVector().ToOrientationRotator();
	FVector actorLocation = FVector(GetActorTransform().GetLocation().X, GetActorTransform().GetLocation().Y, GetActorTransform().GetLocation().Z);
	actorLocation += GetActorTransform().GetRotation().GetRightVector() * Offset.X;
	actorLocation += GetActorTransform().GetRotation().GetForwardVector() * Offset.Y;
	actorLocation += GetActorTransform().GetRotation().GetUpVector() * Offset.Z;
	FVector actorScale = Scale;

	FTransform transform = FTransform(actorRotation, actorLocation, actorScale);

	GetWorld()->SpawnActor<AActor>(BulletBP, transform, spawnParams);
}