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
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay camera"));
}

void UPlayerCameraComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	MoveCamera(DeltaTime);
	//TODO: Auto return YAW
	_axisInfo.Clean();
}

void UPlayerCameraComponent::MoveCamera(float DeltaTime)
{

	FVector2D inputResult = _axisInfo.GetAxis() * _maxCameraRotationSpeed * DeltaTime;
	FRotator rotationToAdd = FRotator(inputResult.Y, inputResult.X, 0);
	FRotator newRotation = _springArm->GetRelativeRotation() + FRotator(rotationToAdd);	
	_springArm->SetRelativeRotation(newRotation);

	if (_axisInfo.GetAxis().X > 0 && _axisInfo.GetAxis().Y > 0)
		UE_LOG(LogTemp, Warning, TEXT("MoveCamera rotationToAdd x:%f y:%f z:%f"), newRotation.Pitch, newRotation.Yaw, newRotation.Roll);
}

void UPlayerCameraComponent::MoveCameraHorizontal(float input)
{
	if (input != 0)
		UE_LOG(LogTemp, Warning, TEXT("MoveCameraHorizontal %f"), input);	

	_axisInfo.SetAxisX(input);
}

void UPlayerCameraComponent::MoveCameraVertical(float input)
{
	if (input != 0)
		UE_LOG(LogTemp, Warning, TEXT("MoveCameraVertical %f"), input);

	_axisInfo.SetAxisY(input);
}

USpringArmComponent* UPlayerCameraComponent::GetSpringArm()
{
	return _springArm;
}
