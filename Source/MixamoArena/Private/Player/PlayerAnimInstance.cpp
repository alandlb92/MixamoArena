// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerAnimInstance.h"



bool UPlayerAnimInstance::IsMovingFoward()
{
	return _verticalInput > 0;
}