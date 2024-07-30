// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <Kismet/GameplayStatics.h>
#include "Blueprint/UserWidget.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Find the widget class in the constructor
	static ConstructorHelpers::FClassFinder<UUserWidget> ScopeWidget(TEXT("/Game/Blueprints/Widgets/WBP_Scope"));
	if (ScopeWidget.Succeeded())
	{
		ScopeWidgetClass = ScopeWidget.Class;
	}
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

	if (ScopeWidgetClass != nullptr)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			UUserWidget* Scope = CreateWidget<UUserWidget>(World, ScopeWidgetClass);
			if (Scope)
			{
				Scope->AddToViewport();
			}
		}
	}
}

void AMyCharacter::TurnLeftRight(const FInputActionValue& Value)
{
	const float TurnValue = Value.Get<float>();
	AddControllerYawInput(TurnValue * TurnLeftRightRate);
}

void AMyCharacter::TurnUpDown(const FInputActionValue& Value)
{
	const float LookUpValue = Value.Get<float>();
	AddControllerPitchInput(-(LookUpValue) * TurnUpDownRate);
}


void AMyCharacter::MoveForwardBackward(const FInputActionValue& Value)
{
	const float moveValue = Value.Get<float>();

	if (moveValue == 0)
	{
		return;
	}

	const FRotator ControllerRotation = GetControlRotation();
	const FRotator YawRotation(0.0, ControllerRotation.Yaw, 0.0);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
	AddMovementInput(Direction, moveValue);
}

void AMyCharacter::MoveLeftRight(const FInputActionValue& Value)
{
	const float moveValue = Value.Get<float>();

	//UE_LOG(LogTemp, Warning, TEXT("TurnUpDown input: %f"), moveValue);

	if (moveValue == 0)
	{
		return;
	}

	const FRotator ControllerRotation = GetControlRotation();
	const FRotator YawRotation(0.0, ControllerRotation.Yaw, 0.0);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(Direction, moveValue);
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
	LineTrace();

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

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMyCharacter::MyJump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AMyCharacter::MyStopJumping);

		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Triggered, this, &AMyCharacter::Shoot);
		EnhancedInputComponent->BindAction(ShootAction, ETriggerEvent::Completed, this, &AMyCharacter::StopShooting);

		EnhancedInputComponent->BindAction(TurnLeftRightAction, ETriggerEvent::Triggered, this, &AMyCharacter::TurnLeftRight);
		EnhancedInputComponent->BindAction(TurnUpDownAction, ETriggerEvent::Triggered, this, &AMyCharacter::TurnUpDown);

		EnhancedInputComponent->BindAction(MoveForwardBackwardAction, ETriggerEvent::Triggered, this, &AMyCharacter::MoveForwardBackward);
		EnhancedInputComponent->BindAction(MoveLeftRightAction, ETriggerEvent::Triggered, this, &AMyCharacter::MoveLeftRight);
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

void AMyCharacter::LineTrace()
{
	FHitResult LookedAt;

	FVector Start = GetActorTransform().GetLocation();
	FVector End = GetActorTransform().GetLocation() + (GetActorForwardVector() * 500);

	//////////////////////////////

	FHitResult LookedAt2;

	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		int32 ViewportWidth, ViewportHeight;
		PlayerController->GetViewportSize(ViewportWidth, ViewportHeight);

		// Calculate the center of the viewport
		FVector2D CenterOfViewport(ViewportWidth / 2.0f, ViewportHeight / 2.0f);

		FVector WorldLocation;
		FVector WorldDirection;

		// De-project the screen position to a world location and direction
		PlayerController->DeprojectScreenPositionToWorld(CenterOfViewport.X, CenterOfViewport.Y, WorldLocation, WorldDirection);

		FVector Start2 = WorldLocation;
		FVector End2 = Start2 + (WorldDirection * 1000.0f); // Extend the line trace to 500 units

		// Draw a debug line from the center of the player's camera
		DrawDebugLine(GetWorld(), Start2, End2, FColor::Yellow, false, 5.0f, 0, 5.0f);

		UE_LOG(LogTemp, Warning, TEXT("Start: %s, End: %s"), *Start2.ToString(), *End2.ToString());

		FCollisionObjectQueryParams ObjectParams2;
		ObjectParams2.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldDynamic);

		FCollisionQueryParams Params2;
		Params2.AddIgnoredActor(this);

		GetWorld()->LineTraceSingleByObjectType(LookedAt2, Start2, End2, ObjectParams2, Params2);

		UE_LOG(LogTemp, Warning, TEXT("Looked at: %s"), *LookedAt2.ToString());
	}


	///////////////////////////////

	FCollisionObjectQueryParams ObjectParams;
	ObjectParams.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldDynamic);

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);


	GetWorld()->LineTraceSingleByObjectType(LookedAt, Start, End, ObjectParams, Params);

	//if (Looked.GetActor())
	//{
	//	// add snapping to object
	//	LookedActor = Looked.GetActor();
	//	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, LookedActor->GetActorLabel());
	//}

	DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 5.f, 0, 5.f);
}