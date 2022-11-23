// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerCharacterMovementComponent.h"
#include "Player/PlayerAnimInstance.h"

void UPlayerCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UPlayerCharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FVector2D input = _inputInfo.GetThumbstickLeft();
	UE_LOG(LogTemp, Warning, TEXT("Input x: %f y: %f"), input.X, input.Y);
	_inputInfo.Clean();
	UE_LOG(LogTemp, Warning, TEXT("CLEANED AWAYS 0, 0 Input x: %f y: %f"), input.X, input.Y);
}

void UPlayerCharacterMovementComponent::Configure(UPlayerAnimInstance* anim)
{
	_anim = anim;
}

void UPlayerCharacterMovementComponent::MoveHorizontal(float input)
{
	if (input != 0)
		UE_LOG(LogTemp, Warning, TEXT("MoveHorizontal %f"), input);

	_inputInfo.SetThumbstickLeftX(input);
	//_anim->_horizontalInput = input;
}


void UPlayerCharacterMovementComponent::MoveVertical(float input)
{
	if (input != 0)
		UE_LOG(LogTemp, Warning, TEXT("MoveVertical %f"), input);

	_inputInfo.SetThumbstickLeftY(input);
	//_anim->_verticalInput = input;
}
