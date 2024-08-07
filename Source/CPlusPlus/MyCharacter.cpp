// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <Kismet/GameplayStatics.h>
#include "Blueprint/UserWidget.h"
#include "Particles/ParticleSystemComponent.h"
#include "NPC.h"
#include "NPC_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"


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
	if (!bIsShooting && !GetCharacterMovement()->IsFalling())
	{
		bIsShooting = true;

		PlayMontageAndSetTimer(ShootingMontage);

		GetWorldTimerManager().SetTimer(TimerHandleForBullet, this, &AMyCharacter::LinesTraceAndAddEffects, 1.0f, false);
	}
}

FVector AMyCharacter::GetLocationForAIMeeting()
{
	return LocationForAIMeeting;
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

void AMyCharacter::LinesTraceAndAddEffects()
{
    bool hit = false;

    FHitResult LookedAtFromCam;

    if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
    {
        int32 ViewportWidth, ViewportHeight;
        PlayerController->GetViewportSize(ViewportWidth, ViewportHeight);

        FVector2D CenterOfViewport(ViewportWidth / 2.0f, ViewportHeight / 2.0f);

        FVector WorldLocation;
        FVector WorldDirection;

        PlayerController->DeprojectScreenPositionToWorld(CenterOfViewport.X, CenterOfViewport.Y, WorldLocation, WorldDirection);

        FVector StartCam = WorldLocation;
        FVector EndCam = StartCam + (WorldDirection * 3000.0f);

        FCollisionObjectQueryParams ObjectParamsCam;
        ObjectParamsCam.AddObjectTypesToQuery(ECollisionChannel::ECC_Pawn);
        ObjectParamsCam.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldStatic);
        ObjectParamsCam.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldDynamic);

        FCollisionQueryParams ParamsCam;
        ParamsCam.AddIgnoredActor(this);

        if (GetWorld()->LineTraceSingleByObjectType(LookedAtFromCam, StartCam, EndCam, ObjectParamsCam, ParamsCam))
        {
            if (LookedAtFromCam.GetActor() && LookedAtFromCam.GetActor()->ActorHasTag("NPC"))
            {
                FHitResult LookedAt;
                FVector Start = GetActorTransform().GetLocation();
                FVector HitDirection = (LookedAtFromCam.ImpactPoint - StartCam).GetSafeNormal();
                float OffsetDistance = 10.f; // Adjust this value as needed
                FVector End = LookedAtFromCam.ImpactPoint + HitDirection * OffsetDistance; // Add offset to ensure hit

                FCollisionObjectQueryParams ObjectParams;
                ObjectParams.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldStatic);
                ObjectParams.AddObjectTypesToQuery(ECollisionChannel::ECC_WorldDynamic);
                ObjectParams.AddObjectTypesToQuery(ECollisionChannel::ECC_Pawn);

                FCollisionQueryParams Params;
                Params.AddIgnoredActor(this);

                if (GetWorld()->LineTraceSingleByObjectType(LookedAt, Start, End, ObjectParams, Params))
                {
                    if (LookedAt.GetActor() && LookedAt.GetActor()->ActorHasTag("NPC"))
                    {
                        ANPC* HitNPC = Cast<ANPC>(LookedAt.GetActor());
                        if (HitNPC)
                        {
                            FLinearColor CurrentColor = HitNPC->GetColor();
                            if (CurrentColor == LastHitColor)
                            {
                                bColorMatch = true;
                                SecondMatchedNPC = HitNPC;

							if (ANPC_AIController* FirstController = FirstMatchedNPC->GetAIController())
							{
								if (ANPC_AIController* SecondController = SecondMatchedNPC->GetAIController())
								{
									//FirstController->SetBoolValueInBlackboard("bIsCoupleCreated", true);
									//SecondController->SetBoolValueInBlackboard("bIsCoupleCreated", true);

									FirstController->GetBlackboardComponent()->SetValueAsBool("bIsCoupleCreated", true);
									SecondController->GetBlackboardComponent()->SetValueAsBool("bIsCoupleCreated", true);

									FirstController->GetBlackboardComponent()->SetValueAsObject("PartnerNPC", SecondMatchedNPC);
									SecondController->GetBlackboardComponent()->SetValueAsObject("PartnerNPC", FirstMatchedNPC);

									// Calculate meeting location between the two NPCs
									//LocationForAIMeeting = (FirstMatchedNPC->GetActorLocation() + SecondMatchedNPC->GetActorLocation()) / 2.0f;
									LocationForAIMeeting = FVector(350, 280, 88);
								}
							}

                                //////////////////////////////////////

							GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("true"));
                            }
                            else
                            {
                                bColorMatch = false;
                                LastHitColor = CurrentColor; // Update to the new color
                                FirstMatchedNPC = HitNPC; // Store the first matched NPC

							GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("false"));
                            }

                            // Store the color somewhere
                            StoredColor = CurrentColor; // Assuming you have a member variable to store the color

                            if (LoveEffect)
                            {
                                UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), LoveEffect, LookedAt.Location);
                                hit = true;
                            }
                        }
                    }
                }
            }
        }
        if (!hit)
        {
            if (MissShootEffect)
            {
                UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), MissShootEffect, LookedAtFromCam.Location);
            }
        }
    }
}

void AMyCharacter::DisappearNPCs()
{
    if (FirstMatchedNPC && FirstMatchedNPC->IsValidLowLevel())
    {
        FirstMatchedNPC->Destroy();
    }

    if (SecondMatchedNPC && SecondMatchedNPC->IsValidLowLevel())
    {
        SecondMatchedNPC->Destroy();
    }

    // Reset pointers after destruction
    FirstMatchedNPC = nullptr;
    SecondMatchedNPC = nullptr;
}