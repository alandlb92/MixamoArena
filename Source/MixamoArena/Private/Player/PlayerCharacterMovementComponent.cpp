// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerCharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/PlayerCameraComponent.h"
#include "GameFramework/Character.h"
#include "Player/PlayerAnimInstance.h"

void UPlayerCharacterMovementComponent::Configure(UPlayerAnimInstance* anim, UPlayerCameraComponent* camera)
{
	_anim = anim;
	_camera = camera;
}

void UPlayerCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	bOrientRotationToMovement = true;
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
	if (_axisInfo.IsMoving())
	{
		FVector input = FVector(_axisInfo.GetAxis(), 0);
		input = _camera->GetSpringArm()->GetRelativeRotation().RotateVector(input);

		FRotator currentActorRotator = GetCharacterOwner()->GetActorRotation();
		FRotator desiredRotation = FVector(input).Rotation();

		float currentYawClamped = FRotator::ClampAxis(currentActorRotator.Yaw);
		float desiredYawClamped = FRotator::ClampAxis(desiredRotation.Yaw);



		_rotationIsSet = FMath::IsNearlyEqual(currentYawClamped, desiredYawClamped, 5);

		UE_LOG(LogTemp, Warning, TEXT("Current yaw: %f Desired yaw: %f"), currentActorRotator.Yaw, desiredRotation.Yaw);
		UE_LOG(LogTemp, Warning, TEXT("currentYawClamped: %f desiredYawClamped: %f"), currentYawClamped, desiredYawClamped);

		if (!_rotationIsSet)
		{
			//Discover the right side
			float	a = FRotator::ClampAxis(currentYawClamped - desiredYawClamped);
			float b = currentYawClamped + desiredYawClamped;
			float cof = b <= a ? 1 : -1;


			FRotator resultRot = currentActorRotator;
			resultRot.Add(0, RotationRate.Yaw * DeltaTime * cof, 0);
			GetCharacterOwner()->SetActorRotation(resultRot);
		}
		else
		{
			FRotator resultRot = currentActorRotator;
			resultRot.Yaw = desiredRotation.Yaw;
			GetCharacterOwner()->SetActorRotation(resultRot);
		}
	}


}

void UPlayerCharacterMovementComponent::Move()
{
	if (_rotationIsSet)
	{
		FVector input = FVector(_axisInfo.GetAxis(), 0);
		input = _camera->GetSpringArm()->GetRelativeRotation().RotateVector(input);
		AddInputVector(input);
	}
}

void UPlayerCharacterMovementComponent::MoveAnimation()
{
	float velocityScale = Velocity.Length() / GetMaxSpeed();
	//UE_LOG(LogTemp, Warning, TEXT("Velocity %f"), Velocity.Length());
	//UE_LOG(LogTemp, Warning, TEXT("MaxSpeed %f"), GetMaxSpeed());
	//UE_LOG(LogTemp, Warning, TEXT("velocityScale %f"), velocityScale);
	_anim->_velocityScale = velocityScale;
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
