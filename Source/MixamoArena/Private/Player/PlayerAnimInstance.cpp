// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerAnimInstance.h"



bool UPlayerAnimInstance::IsMoving()
{
	return _velocityScale > 0;
}