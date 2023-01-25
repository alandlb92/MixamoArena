// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerCharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/PlayerCameraComponent.h"
#include "GameFramework/Character.h"
#include "Player/PlayerAnimInstance.h"

UPlayerCharacterMovementComponent::UPlayerCharacterMovementComponent()
{
	bOrientRotationToMovement = false;
}

void UPlayerCharacterMovementComponent::Configure(UPlayerAnimInstance* anim, UPlayerCameraComponent* camera)
{
	_anim = anim;
	_camera = camera;
}

void UPlayerCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UPlayerCharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AdjustPlayerRotation(DeltaTime);
	Move();	
	MoveAnimation();	

	_axisInfo.Clean();
}

void UPlayerCharacterMovementComponent::AdjustPlayerRotation(float DeltaTime)
{
	if (!IsMovingOnGround())
		return;

	if (_axisInfo.IsInUse())
	{
		FVector input = FVector(_axisInfo.GetAxis(), 0);
		input = _camera->GetSpringArm()->GetRelativeRotation().RotateVector(input);
		_lastDesireRotation = FVector(input).Rotation();
	}

	FRotator currentActorRotator = GetCharacterOwner()->GetActorRotation();
	float currentYawClamped = FRotator::ClampAxis(currentActorRotator.Yaw);
	float desiredYawClamped = FRotator::ClampAxis(_lastDesireRotation.Yaw);

	float currentSum = currentYawClamped + MAX_ANGLE;
	float distanceRight = MAX_ANGLE - (currentSum - desiredYawClamped);
	distanceRight = distanceRight < 0 ? MAX_ANGLE + distanceRight : distanceRight;
	float distanceLeft = MAX_ANGLE - distanceRight;

	_rotationIsSet = distanceLeft < _rotateAdjustVelocity / 100 || distanceRight < _rotateAdjustVelocity / 100;

	if (!_rotationIsSet)
	{
		float sideToRotate = distanceRight > MAX_ANGLE / 2 ? -1 : 1;
		FRotator toadd = FRotator(0, _rotateAdjustVelocity * DeltaTime * sideToRotate, 0);
		GetCharacterOwner()->AddActorLocalRotation(toadd);
	}
	else if (_axisInfo.IsInUse())
	{
		FRotator resultRot = currentActorRotator;
		resultRot.Yaw = _lastDesireRotation.Yaw;
		GetCharacterOwner()->SetActorRotation(resultRot);
	}
}

void UPlayerCharacterMovementComponent::Move()
{
	if (!_rotationIsSet)
		return;

	FVector input = FVector(_axisInfo.GetAxis(), 0);
	input = _camera->GetSpringArm()->GetRelativeRotation().RotateVector(input);
	AddInputVector(input);

}

void UPlayerCharacterMovementComponent::MoveAnimation()
{
	_anim->_maxVelocity = GetMaxSpeed();
	_anim->_xVelocity = Velocity.X;
	_anim->_yVelocity = Velocity.Y;
	_anim->_zVelocity = Velocity.Z;
	_anim->_movingInGround = IsMovingOnGround();
}


void UPlayerCharacterMovementComponent::MoveHorizontal(float input)
{
	if (input != 0)
		UE_LOG(LogTemp, Warning, TEXT("MoveHorizontal %f"), input);

	_axisInfo.SetAxisY(input);

}

void UPlayerCharacterMovementComponent::MoveVertical(float input)
{
	if (input != 0)
		UE_LOG(LogTemp, Warning, TEXT("MoveVertical %f"), input);

	_axisInfo.SetAxisX(input);
}

void UPlayerCharacterMovementComponent::Jump()
{
	if (!_rotationIsSet || !IsMovingOnGround())
		return;

	DoJump(false);
}

bool UPlayerCharacterMovementComponent::IsMoving() const
{
	return Velocity.X != 0 && Velocity.Y != 0 && Velocity.Z != 0;
}