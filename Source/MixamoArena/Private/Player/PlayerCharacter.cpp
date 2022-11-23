// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerCharacter.h"
#include "Player/PlayerAnimInstance.h"
#include "Engine/SkeletalMesh.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Player/PlayerCharacterMovementComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;

	_springArm = CreateAbstractDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	_springArm->SetupAttachment(RootComponent);
	_springArm->TargetArmLength = 400.0f;
	_springArm->bEnableCameraLag = true;
	_springArm->CameraLagSpeed = 3.0f;
	_springArm->SetRelativeLocation(FVector(0, 0, 100));

	_springArm->bInheritPitch = false;
	_springArm->bInheritYaw = false;
	_springArm->bInheritRoll = false;

	_camera = CreateAbstractDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	_camera->SetRelativeLocationAndRotation(FVector(0, 0, 0), FRotator(0, 0, 0));
	_camera->SetupAttachment(_springArm, USpringArmComponent::SocketName);

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	_movementComponent = Cast<UPlayerCharacterMovementComponent>(GetMovementComponent());
	if (_movementComponent == nullptr)
		UE_LOG(LogTemp, Warning, TEXT("_movementComponent == nullptr begin play"));

	_movementComponent->Configure(Cast<UPlayerAnimInstance>(GetMesh()->GetAnimInstance()));
	SetupGameplayInput();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APlayerCharacter::SetupGameplayInput()
{	
	InputComponent->BindAxis("Move_Horizontal", _movementComponent, &UPlayerCharacterMovementComponent::MoveHorizontal);
	InputComponent->BindAxis("Move_Vertical", _movementComponent, &UPlayerCharacterMovementComponent::MoveVertical);
	InputComponent->BindAction("Test", EInputEvent::IE_Pressed, this, &APlayerCharacter::Test);
}

void APlayerCharacter::Test()
{
	UE_LOG(LogTemp, Warning, TEXT("TEST"));

}