// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerCameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

UPlayerCameraComponent::UPlayerCameraComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UPlayerCameraComponent::Configure(USpringArmComponent* springArm)
{
	_springArm = springArm;
}

void UPlayerCameraComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UPlayerCameraComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	MoveCamera(DeltaTime);
	//TODO: Auto return YAW
	//TODO: Clamp 
	_axisInfo.Clean();
}

void UPlayerCameraComponent::MoveCamera(float DeltaTime)
{
	if (_springArm) 
	{
		FVector2D inputResult = _axisInfo.GetAxis() * _maxCameraRotationSpeed * DeltaTime;
		FRotator rotationToAdd = FRotator(inputResult.Y, inputResult.X, 0);
		FRotator newRotation = _springArm->GetRelativeRotation() + FRotator(rotationToAdd);
		newRotation.Pitch = FMath::Clamp(newRotation.Pitch, -85, 85);
		_springArm->SetRelativeRotation(newRotation);
	}
}

void UPlayerCameraComponent::MoveCameraHorizontal(float input)
{
	_axisInfo.SetAxisX(input);
}

void UPlayerCameraComponent::MoveCameraVertical(float input)
{
	_axisInfo.SetAxisY(input);
}

USpringArmComponent* UPlayerCameraComponent::GetSpringArm()
{
	return _springArm;
}
