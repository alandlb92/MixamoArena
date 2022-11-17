// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerCharacterMovementComponent.h"
#include "Player/PlayerAnimInstance.h"



void UPlayerCharacterMovementComponent::Configure(UPlayerAnimInstance* anim)
{
	_anim = anim;
}

void UPlayerCharacterMovementComponent::MoveHorizontal(float input)
{
	if (input != 0)
		UE_LOG(LogTemp, Warning, TEXT("MoveHorizontal %f"), input);

	_anim->_horizontalInput = input;
}


void UPlayerCharacterMovementComponent::MoveVertical(float input)
{
	if (input != 0)
		UE_LOG(LogTemp, Warning, TEXT("MoveVertical %f"), input);

	_anim->_verticalInput = input;
}
